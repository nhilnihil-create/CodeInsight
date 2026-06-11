// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

const ll MOD = 1e9+7;
ll k;
vector<vector<int>> graph(100001);

template<class T>
T pow(long long a, long long b, T mod){
    if(b == 0) return 1;
    if(b % 2 == 0){
        T d = pow(a,b/2,mod);
        return (d*d)%mod;
    }else return a%mod*pow(a,b-1,mod)%mod;
}

// (k-2)Pn
ll perm_table[100001];
ll perm(ll n){
    if(perm_table[n] != 0) return perm_table[n];
    ll ret = 1LL;
    for(ll i = k-2; i >= (k-n-1); --i) ret = ret*i%MOD;
    return perm_table[n] = ret;
}

vector<bool> visited(100001, false);
ll dfs(int now){
    if(now != 0 && graph[now].size() == 1) return 1LL;
    visited[now] = true;
    ll ret = 1LL;
    if(now == 0) for(ll i = k; i >= k-graph[now].size(); --i) ret = ret*i%MOD;
    else ret *= perm(graph[now].size()-1);
    
    rep(i,graph[now].size()){
        int next = graph[now][i];
        if(visited[next]) continue;
        ret = ret*dfs(next)%MOD;
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n >> k;
    int a, b;
    rep(i,n-1){
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if(n == 1 && k == 1){
        cout << 1 << endl;
        return 0;
    }else if(k == 1){
        cout << 0 << endl;
        return 0;
    }

    cout << dfs(0) << endl;
}