#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using product = pair<ll,ll>;
using graph = vector<vector<ll>>;
using vll = vector<ll>;

bool second_compare(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.second < b.second;
}

int main(){
    ll N;
    cin>>N;
    vector<product> robots(N);
    for(ll i=0;i<N;i++)
    {
        ll x,l;cin>>x>>l;
        ll start=x-l;
        ll terminal=x+l;
        robots[i]=make_pair(start,terminal);
    }
    sort(robots.begin(),robots.end(),second_compare);
    ll res=0;
    ll cur=LLONG_MIN;
    for(auto p:robots)
    {
        if(cur<=p.first)
        {
            res++;
            cur=p.second;
        }
    }
    cout<<res;
    return 0;
}