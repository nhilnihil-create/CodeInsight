#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mtv(kit) cout<<#kit<<" - "<<kit<<"\n";
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map

const ll N = 2e5 + 5;
vector<ll>adj[N];
ll C[N];

void dfs(ll n, ll A, ll p){
    C[n] += A;
    for(auto x : adj[n]){
        if(x != p){
            dfs(x,C[n],n);
        }
    }
}

void doit(){
    ll n, i, q, x, y;
    cin >> n >> q;
    rep(i,0,n-1){
        cin >> x >> y;
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1);
    }
    while(q--){
        cin >> x >> y;
        C[x-1] += y;
    }
    dfs(0,0,-1);
    rep(i,0,n){
        cout << C[i] << " ";
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}
