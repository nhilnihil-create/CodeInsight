#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t;
    cin>>n;
    ll arr[n],brr[n]={0};
    for(i=0;i<n;i++) cin>>arr[i];
    for(i=0;i<n-1;i++) if(arr[i]>=arr[i+1]) brr[i]=1;
    ll count=0,mx=0;
    for(i=0;i<n;i++)
    {
        if(brr[i]==1) count++;
        else count=0;
        mx=max(count,mx);
    }
    cout<<mx;
}