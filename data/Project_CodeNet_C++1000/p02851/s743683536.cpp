#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處
const int MAXN = 2e5 + 2;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K; cin >> N >> K;
    LL A[MAXN];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        --A[i];
    }
    if (K == 1) {
        cout << 0 << endl;
        return 0;
    }
    map<LL, int> m;
    LL acc = 0;
    LL ans = 0;
    queue<LL> q;
    m[0] = 1;
    q.push(0);
    for (int i = 0; i < N; ++i) {
        acc += A[i];
        ans += m[acc%K];
        // cout << "ans " << ans << endl;
        ++m[acc%K];
        q.push(acc%K);
        // for (auto x : m) {
        //     cout << x.first << ' ' << x.second << endl;
        // }
        if (q.size() == K) {
            --m[q.front()];
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
