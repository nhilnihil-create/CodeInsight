#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const long long P = 1000000007;

vector<int> G[N+5];

int n, k;

long long ans;

long long fact[N+5];

template<typename T> T inv(T a){
    T res = 1, n = P - 2; a %= P;
    while (n){ if (n & 1) res = res * a % P; a = a * a % P; n >>= 1; }
    return res;
}

void dfs(int u, int p){
    if (k < 1 + (int)G[u].size()) ans = 0;
    else ans = ans * (fact[k - 1 - (bool)p] * inv(fact[k - 1 - G[u].size()]) % P) % P;
    for (int v : G[u]) if (v != p){
        dfs(v, u);
    }
}

int main(){
    fact[0] = 1;
    for (int i = 1; i <= N; ++i){
        fact[i] = fact[i-1] * i % P;
    }
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n-1; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans = k;
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}