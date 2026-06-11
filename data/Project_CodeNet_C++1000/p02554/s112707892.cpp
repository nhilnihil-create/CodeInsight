#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
#define LARGE 1000000007

int main() {
    ll n;
    cin >> n;

    ll a=1, b=1, c=1;
    while(n > 0) {
        a *=10;
        b*= 9;
        c*= 8;
        a %= LARGE;
        b %= LARGE;
        c %= LARGE;
        n--;
    }
    b = (b*2);
    b %= LARGE;
    ll ans = a - b + c;
    if (ans < 0) ans += LARGE;

    cout << ans << endl;

	return 0;
}
