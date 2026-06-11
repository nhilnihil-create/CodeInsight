#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,m;
    cin>>n;
    ll sum=0;
    ll arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    for(i=0;i<n;i++) for(j=0;j<n;j++)
    {
        if(i!=j)
            sum+=arr[i]*arr[j];
    }
    cout<<sum/2;
}