#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

ll N;
vector<vector<ll>> G(100010);
vector<ll> memo(100010);
map<Pll,ll> mp;
ll K = 1; 

ll dfs(ll v, ll c){
    ll cc = 1;
    for(auto& u:G[v]){
        if(memo[u] != 0) continue;
        memo[u] = 1;
        if(cc == c) cc++;
        cmax(K,cc);
        mp[Pll(v,u)] = cc;
        mp[Pll(u,v)] = cc;
        dfs(u,cc);
        cc++;
    }
    return 0;
}

int main(){
    cin >> N;
    ll a,b;
    vector<Pll> v;
    rep(i,N-1){
        cin >> a >> b;
        a--;b--;
        v.push_back(Pll(a,b));
        G[a].push_back(b);
        G[b].push_back(a);
    }
    memo[0] = 1;
    dfs(0,0);
    cout << K << endl;
    rep(i,N-1){
        cout << mp[v[i]] << endl;
    }
}