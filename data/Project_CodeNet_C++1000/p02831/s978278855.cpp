#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using P = pair<int, int>;

int gcd(ll a, ll b) {
    if(a%b == 0) {
        return(b);
    } else {
        return(gcd(b, a%b));
    }
}

int main() {
    ll a, b;
    cin >> a >> b;

    cout << a * b / gcd(a, b) << endl;
	return 0;
}
