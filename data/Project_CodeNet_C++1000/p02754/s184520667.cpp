#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    ll devided = N / (A + B);
    ll left = N % (A + B);

    ll ans = 0;
    ans += devided * A;
    ans += min(A, left);

    cout << ans << endl;

    return 0;
}
