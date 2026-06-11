#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2;
    cin >> A1 >> A2;
    cin >> B1 >> B2;

    ll tmp1 = (B1 - A1) * T1;
    ll tmp2 = (B2 - A2) * T2 + tmp1;

    if (tmp2 == 0) {
        cout << "infinity" << endl;
        return 0;
    }
    if ((tmp2 < 0 && tmp1 < 0) || (tmp2 > 0 && tmp1 > 0)) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = (-(tmp1 / tmp2) + 1) * 2 - 1;
    if (tmp1 % tmp2 == 0)
        ans--;
    cout << max(ans, 0LL) << endl;

    return 0;
}
