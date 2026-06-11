#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;

int main() {
	ll n;
    cin >> n;

    ll t = (ll)sqrt((double)n);
    ll a=1;
    for (ll i=1; i <= t; i++) {
        if ((n%i) == 0) a = i;
    }
    ll b = n/a;
    cout << a+b-2 << endl;

	return 0;
}
