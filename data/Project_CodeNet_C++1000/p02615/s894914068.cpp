#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }

    // 昇順にソート
    sort(a.begin(), a.end());

    // \Sigma_{k=1}^{N-1} A_{N - \lfloor k/2 \rfloor} が答え
    long long ans = 0;
    for (int k = 1; k < n; k++) {
        // 添字
        int index = n - floor(k / 2);
        ans += a.at(index - 1);
    }
    cout << ans << endl;
}
