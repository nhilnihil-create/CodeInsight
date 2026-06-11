#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
#define i(x) cin>>x
#define fr(n,x) for(ll n=0;n<x;n++)
#define pf(x) cout<<x
const ll mod=1e9+7 ;


int main()
{
    ll x;
    cin>>x;
    map<string,ll>ms;
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    fr(n,x)
    {
        string j;
        cin>>j;
        sort(j.begin(),j.end());
        ms[j]++;
    }
    ll res=0;
    for(auto j:ms)
    {
        ll v=j.second;
        res+=(v*(v-1))/2;
    }
    cout<<res;
}