#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int capacity;
    cout<<"Please enter the capacity of the knapsack : ";
    cin>>capacity;

    int n;
    cout<<"Please enter the number of weights : ";
    cin>>n;
    int profit[n],weight[n];

    cout<<"Please the profit vector :\n";
    for(int i=0;i<n;i++)
        cin>>profit[i];
    cout<<"Please enter the weights vector :\n";
    for(int i=0;i<n;i++)
        cin>>weight[i];

    priority_queue<pair<int,pair<int,int> > > pq;

    for(int i=0;i<n;i++)
    {
        int temp = profit[i] / weight[i];
        pair<int,int> p1 = make_pair(profit[i],weight[i]);
        pair<int,pair<int,int> > p2 = make_pair(temp,p1);
        pq.push(p2);
    }

    double totalprofit = 0;
    while(!pq.empty() && capacity>0)
    {
        if(pq.top().second.second <= capacity )
        {
            totalprofit += (double)pq.top().second.first;
            capacity -= pq.top().second.second;
        }

        else
        {
            double temp = ((double)capacity / (double)pq.top().second.second );
            capacity -= (capacity / pq.top().second.second );
            totalprofit += (double)temp*pq.top().second.first;
        }
        pq.pop();
    }

    cout<<"The total profit is "<<totalprofit;

}



