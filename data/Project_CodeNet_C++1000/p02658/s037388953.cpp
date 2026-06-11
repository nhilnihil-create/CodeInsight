//sppsfver - 05.08.2020
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair <ll, ll>;

ll n, a, ans = 1;
bool flag, zero;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        if (a == 0) return cout << 0 << endl, 0;
        a <= (ll)(1e18)/ans ? ans *= a : flag = 1;
    }
    cout << (flag ? -1 : ans) << endl;
	return 0;
}
