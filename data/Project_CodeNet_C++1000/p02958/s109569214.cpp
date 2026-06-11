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
    ll a,b,i,j,n,t,c;
    cin>>n;
    ll arr[n],brr[n];
    for(i=1;i<=n;i++) brr[i-1]=i;
    for(i=0;i<n;i++) cin>>arr[i];
    ll count=0;
    for(i=0;i<n;i++) if(arr[i]!=brr[i]) count++;
    if(count<=2) cout<<"YES";
    else cout<<"NO";
    
}