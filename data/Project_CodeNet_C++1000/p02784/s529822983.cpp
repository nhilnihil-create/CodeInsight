#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vl vector
using namespace std;
int main()
{
    ll n,m,a=0,i,j;
    cin>>m>>n;
    ll arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    ll sum=0;
    for(i=0;i<n;i++) sum+=arr[i];
    if(sum>=m) cout<<"Yes";
    else cout<<"No";
}