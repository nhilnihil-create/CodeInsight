// 6/23 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

vector<int> f;  // iマス目以降で一番小さい0のマス。

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> S(N+1);
    S[0] = 0;
    rep(i, N) {
        // S[i+1] = (S[i] + A[i]) % K;
        S[i+1] = S[i] + A[i];
    }

    map<int, int> mp;

    ll ans = 0;

    // int left = 0;
    // for (int right = 1; right <= N; right++) {
    //     if (right < K) {
    //         int t = (S[right] - right) % K;
    //         mp[t] += 1;
    //     }
    // }

    queue<int> q;
    // rep(j, N+1) {
    //     ans += mp[S[j]];
    //     mp[S[j]]++;
    //     q.push(S[j]);
    //     if (q.size() == K) {
    //         mp[q.front()]--;
    //         q.pop();
    //     }
    // }

    rep(j, N+1) {
        int v = (S[j]-j) % K;
        ans += mp[v];
        mp[v]++;
        q.push(v);
        if (q.size() == K) {
            mp[q.front()]--;
            q.pop();
        }
    }

    cout << ans << endl;
    return 0;
}