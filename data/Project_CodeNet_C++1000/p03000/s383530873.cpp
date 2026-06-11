#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> L(N);
    rep(i, N) cin >> L.at(i);

    vector<int> D(N + 1);
    D.at(0) = 0;
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        D.at(i) = D.at(i - 1) + L.at(i - 1);
        if (D.at(i) <= X) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
