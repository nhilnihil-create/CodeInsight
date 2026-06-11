#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    ll H, N;
    cin >> H >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);

    ll sum = 0;
    rep(i, N) sum += A.at(i);

    string ans = "No";
    if (H <= sum) {
        ans = "Yes";
    }

    cout << ans << endl;

    return 0;
}
