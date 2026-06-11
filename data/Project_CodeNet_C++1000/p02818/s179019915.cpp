#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a, b, k;
    cin >> a >> b >> k;
    if (k <= a) {
		cout << a - k << " " << b;
	} else {
		k -= a;
		a = 0;
		b -= k;
		cout << 0 << " " << max(b, 0LL);
	}
    return 0;
}
