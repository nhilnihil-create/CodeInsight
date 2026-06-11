#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

set<pair<ll,ll>> S;
void dfs(ll N, ll K, ll num, ll last, ll sum) {
    if (num > N + 1) return;
    for (ll i = last + 1; i <= N; i++) {
        if (num >= K) S.insert({num, sum + i});
        dfs(N, K, num+1, i, sum + i);
    }
}

ll solve(ll N, ll K) {
    dfs(N, K, 1, -1, 0);
    return S.size();
}

ll solve2(ll N, ll K) {
    ll res = 0;
    for (int i = K; i <= N + 1; i++) {
        /*
        ll low = i * (i + 1) / 2;
        ll hig = (N - i + 1) * i + (i * (i + 1) / 2);
        res += hig - low + 1;
        */
        res += (N - i + 1) * i + 1;
        res %= 1000000007;
    }
    return res;
}

int main() {
    ll N, K; cin >> N >> K;
    cout << solve2(N, K) << endl;
}
