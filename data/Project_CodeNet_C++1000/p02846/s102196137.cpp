#include <bits/stdc++.h>

using namespace std;
using ll=int64_t;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using mii = map<int, int>;
using vi=vector<int>;
using vii=vector<vi>;
using vl=vector<ll>;
using vll=vector<vl>;
using tpi=tuple<int, int, int>;

int main() {
    ll T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

    ll h1 = T1 * (A1 - B1);
    ll h2 = T2 * (A2 - B2);
    if (signbit(h1) == signbit(h2)) {
        cout << 0 << endl;
        return 0;
    }

    if (h1 >= 0) {
        h1 *= -1;
        h2 *= -1;
    }

    if (h1 + h2 == 0) {
        cout << "infinity" << endl;
        return 0;
    }

    if (h1 + h2 < 0) {
        cout << 0 << endl;
        return 0;
    }


    ll q = -h1 / (h1 + h2);
    ll m = -h1 % (h1 + h2);

    ll ans = 2 * q;
    if (m != 0) {
        ans++;
    }

    cout << ans << endl;
    return 0;
}
