#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
#define PRYES(x) PR((x) ? "Yes" : "No")
const long long INF = numeric_limits<long long>::max();
int main() {
    ll A;
    string B;
    cin >> A >> B;

    auto itr = B.find('.');
    ll b1    = A * stoll(B.substr(0, itr));
    ll b2    = A * stoll(B.substr(itr + 1, B.size() - itr - 1)) / 100;

    ll ans = b1 + b2;
    PR(ans);
    return 0;
}