#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,i;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++) arr[i]=i+1;
    ll sum=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]%5==0 || arr[i]%3==0) arr[i]=0;
    }
    for(i=0;i<n;i++) sum+=arr[i];
    cout<<sum;
}