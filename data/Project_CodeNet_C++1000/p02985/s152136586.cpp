#include <bits/stdc++.h>
using namespace std;
const int MAX = 410000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
//invの要素にはiの逆元が格納されている
//前処理
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;//i!(mod MOD)を計算
        inv[i] = MOD - inv[MOD%i]* (MOD / i) % MOD;//iの逆元を計算
        finv[i] = finv[i - 1] * inv[i] % MOD;//i!(mod MOD)の逆元を計算
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;//nCk = n!/(k!*(n-k)!)を計算
}
//例のアレ
long long nPm(int n, int m){
    if(n < m) return 0;
    if(n < 0 || m < 0) return 0;
    return fac[n] * finv[n - m] % MOD;
}
long long ans = 1;
vector<vector<int>> G;
int N, K;
vector<int> used;
void dfs(int s){
    if(K - 2 < (int)G[s].size() - 1){
        ans *= 0;
        return;
    }
    if(s != 0){
        ans *= nPm(K - 2, (int)G[s].size() - 1);
    }
    else ans *= nPm(K - 1, (int)G[s].size());
    ans %= MOD;
    used[s] = 1;
    for(int j: G[s]) {
        if(used[j] == -1) dfs(j);
    }
}
int main(){
    cin >> N >> K;
    COMinit();
    G.resize(N);
    used.resize(N, -1);
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ans *= K;
    dfs(0);
    cout << ans << endl;
}
