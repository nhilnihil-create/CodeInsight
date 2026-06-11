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
vector<ll> memo(100010);
vector<vector<ll>> G(100010);
map<Pll,ll> mp;
void dfs(ll v, ll c){
    if(memo[v])return;
    memo[v] = 1;
    ll j = 1;
    rep(i,G[v].size()){
        if(j == c)j++;
        if(memo[G[v][i]])continue;
        dfs(G[v][i], j);
        mp[Pll(v,G[v][i])] = j;
        mp[Pll(G[v][i],v)] = j;
        //CG[v][i] = -j;
        //CG[G[v][i]][v] = -j;
        j++;
    }
}

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N-1),b(N-1);
    rep(i,N-1){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    ll K = 0;
    rep(i,N){
        cmax(K, G[i].size());
    }
    cout << K << endl;
    //CG = G;
    dfs(0,0);
    rep(i,N-1){
        cout << mp[Pll(a[i],b[i])] << endl;
    }
}
