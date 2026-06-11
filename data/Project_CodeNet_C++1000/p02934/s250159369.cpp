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
    vector<double> A(N);
    rep(i, N) cin >> A.at(i);

    double revSum = 0;
    rep(i, N) {
        revSum += 1 / A.at(i);
    }
    double ans = 1 / revSum;

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
