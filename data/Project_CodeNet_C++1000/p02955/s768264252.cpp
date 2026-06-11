#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }

    auto func = [&](int g) {
        priority_queue<int> que;
        ll res = 0;
        for (int i = 0; i < N; ++i) {
            res += g - A[i] % g;
            que.push(g - A[i] % g);
        }
        int cnt = res / g;
        for (int i = 0; i < cnt; ++i) {
            res -= que.top();
            que.pop();
        }
        return res;
    };

    int ans = 0;
    for (int i = 1; i * i <= sum; ++i) {
        if (sum % i)
            continue;
        if (func(i) <= K)
            ans = max(ans, i);
        if (func(sum / i) <= K)
            ans = max(ans, sum / i);
    }

    cout << ans << endl;
    return 0;
}
