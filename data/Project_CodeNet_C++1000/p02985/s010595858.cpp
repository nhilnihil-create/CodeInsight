#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef int64_t Int;
const Int MOD = 1e9+7;

int N, K; 
vector<vector<int>> G(100010);
vector<bool> visited(100010, false);
vector<Int> f;


//---------- べき乗 ----------
Int power(Int a, Int n){
    if(a == 0) return 0;
    if(n == 0) return 1;
    
    Int res = 1;
    while(n > 0){
        if(n % 2 == 1) res = res * a % MOD;
        a = a * a % MOD; n /= 2;
    }
    return res;
}

//---------- 逆元 ----------
Int inv(Int a){
    return power(a, MOD-2);
}

//---------- 階乗 ----------
vector<Int> factorial(Int n){
    vector<Int> res(n+1, 1);
    for(int i=1; i<=n; i++) res[i] = i * res[i-1] % MOD;

    return res; // nまでの階乗の配列を返す
}

//--------- 順列 ---------
Int perm(Int n, Int r){
    if(r > n || n < 0) return 0;
    return f[n] * inv(f[n-r]) % MOD;
}


Int dfs(int v){
    visited[v] = true; Int res;
    if(v == 0){
        res = K * perm(K-1,G[v].size()) % MOD; 
    } else {
        res = perm(K-2, G[v].size()-1) % MOD;
    }

    rep(i, G[v].size()){
        if(visited[G[v][i]]) continue;
        res = res * dfs(G[v][i]) % MOD;
    }

    return res;
}

int main(){
    cin >> N >> K;

    rep(i, N-1){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    f = factorial(K);
    cout << dfs(0) << endl;
}