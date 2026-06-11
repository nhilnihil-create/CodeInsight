#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    rep(i, M) cin >> A.at(i);

    ll workDays = 0;
    rep(i, M) {
        workDays += A.at(i);
    }

    ll ans = (N - workDays >= 0) ? N - workDays : -1;

    cout << ans << endl;

    return 0;
}
