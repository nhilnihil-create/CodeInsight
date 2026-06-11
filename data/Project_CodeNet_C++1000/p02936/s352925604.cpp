#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

vector<vector<ll>> V;
vector<bool> seen(200010, 0);
vector<ll> Ans(200010, 0);

void dfs(ll x){

    ll L = V[x].size();

    seen[x] = 1;

rep(i, 0, L){

    if(seen[V[x][i]])continue;

    Ans[V[x][i]] += Ans[x];

    dfs(V[x][i]);
    
}

}

int main(){
ll N, Q;cin >> N >> Q;

V.resize(N + 1);

rep(i, 1, N){

    ll a, b;cin >> a >> b;

    V[a].push_back(b);
    V[b].push_back(a);

}

rep(i, 0, Q){

    ll p, q;cin >> p >> q;

    Ans[p] += q;

}

dfs(1);

rep(i, 1, N + 1)cout << Ans[i] << endl;

}


