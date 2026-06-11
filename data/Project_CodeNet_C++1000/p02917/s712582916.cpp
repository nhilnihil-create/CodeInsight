#include<bits/stdc++.h>
#define ll long long
#define ld long double 
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t;
    cin>>n;
    n--;
    ll arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    ll sum=arr[0]+arr[n-1];
    for(i=0;i<n-1;i++)
    {
        if(arr[i]<=arr[i+1]) sum+=arr[i];
        else sum+=arr[i+1];
    }
    cout<<sum;
}