#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

const ll mod=1e9+7;

vector<vector<ll>> to;

ll n,k;

ll ans=1;

void dfs(ll v,ll p=-1){
    ll c;
    if(p==-1) c=k-1;
    else c=k-2;
    for(auto x:to[v]){
        if(x==p) continue;
        ans*=c;
        ans%=mod;
        c--;
        dfs(x,v);
    }
    return ;
}

int main(){
    cin >> n >> k;
    to=vector<vector<ll>>(n);
    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs(0);
    ans*=k;
    ans%=mod;
    cout << ans << endl;
    return 0;
}