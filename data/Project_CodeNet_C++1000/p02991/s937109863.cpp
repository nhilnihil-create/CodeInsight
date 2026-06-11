
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

inline int topbit(unsigned long long x){
	return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
	return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){//popcount%2
	return __builtin_parity(x);
}



template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e15;

const ll mod=1e9+7;

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> u(m),v(m);
    vector<vector<ll>> to(n);
    rep(i,m){
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        to[u[i]].push_back(v[i]);
    }
    ll s,t;
    cin >> s >> t;
    s--; t--;
    vector<vector<ll>> d(n,vector<ll>(3,INF));
    vector<ll> ans(n,-1);
    queue<pll> que;
    que.push({s,0});
    d[s][0]=0;
    while(!que.empty()){
        pll x=que.front();
        que.pop();
        for(auto v:to[x.fi]){
            ll r=(d[x.fi][x.se]+1)%3;
            if(d[v][r]!=INF){
                continue;
            }
            d[v][r]=d[x.fi][x.se]+1;
            que.push({v,r});
        }
    }
    
    if(d[t][0]!=INF){
        cout << d[t][0]/3 << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}