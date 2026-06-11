#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;

const ll MOD = 1000000007;
vector<vector<int>> G;
ll K;

ll dfs(int n, int p) {
    ll k;
    if(p==-1) k=K-1;
    else k=K-2;

    ll ans = 1;
    for (auto e : G[n]) {
        if (e == p) continue;
        ans *= k;
        ans %= MOD;
        ans *= dfs(e, n);
        ans %= MOD;
        k = k -1;
    }
    return ans%MOD;
}

int main() {
    int N;
    cin >> N >> K;
    G.resize(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << K*dfs(0, -1)%MOD << endl;
}