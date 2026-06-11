//author: Harsh Nema
#include <bits/stdc++.h>
#define ll long long int
#define F first
#define S second
const ll mod = 1e9 + 7;
const ll INF = 922337203685477;
#define pb push_back
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
vector<ll>adj[100005];
int main()
{
    fastio;
    ll n=0,m=0;
    cin>>n>>m;
    ll x=0,y=0;
    for(ll i=0;i<n;++i){
        cin>>x>>y;
        adj[x].pb(y);
    }
    ll ans=0;
    priority_queue<ll>pq;
    for(ll i=m-1;i>=0;--i){  //iterating through each day
        for(auto x:adj[m-i]) pq.push(x);
        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
    }
    cout<<ans;
    return 0;
}
