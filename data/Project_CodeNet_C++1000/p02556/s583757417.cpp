#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned int ui;
#define infin (ll)(pow(10,9)+7)
using namespace std;
int main()
{
    ll n,x,y;
    ll diff_min=1000000000,diff_max=-1*pow(10,10),sum_min=10000000000,sum_max=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if (x+y>sum_max)
           sum_max=x+y;
        if(x+y<sum_min)
          sum_min=x+y;
        if (x-y<diff_min)
           diff_min=x-y;
        if (x-y>diff_max)
           diff_max=x-y;
    }
    cout<<max(diff_max-diff_min,sum_max-sum_min);
}