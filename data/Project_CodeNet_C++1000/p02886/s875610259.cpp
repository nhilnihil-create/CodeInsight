#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N;
    cin >> N;
    vector<int> d(N);
    rep(i, N) cin >> d.at(i);

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            ans += d.at(i) * d.at(j);
        }
    }

    cout << ans << endl;

    return 0;
}
