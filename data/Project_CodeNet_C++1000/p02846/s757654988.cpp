#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
#ifdef LOCAL_EXEC
	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

    LL t1, t2; cin >> t1 >> t2;
    LL a1, a2; cin >> a1 >> a2;
    LL b1, b2; cin >> b1 >> b2;

    LL v1 = b1 - a1, v2 = b2 - a2;
    if (v1 < 0) {
        v1 *= -1;
        v2 *= -1;
    }

    LL delta = v1 * t1 + v2 * t2;
    if (delta > 0) {
        cout << "0\n";
        return 0;
    }
    if (delta == 0) {
        cout << "infinity\n";
        return 0;
    }
    delta *= -1;
    LL h = v1 * t1;
    LL ans = 2 * (h / delta);
    if (h % delta) ++ans;
    cout << ans << endl;

	return 0;
}
