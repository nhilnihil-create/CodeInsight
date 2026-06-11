#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
    ll N; cin >> N;
    ll ans = 0;
    rep(i,N) {
        if ((i+1) % 3 == 0) {
        }
        else if ((i+1) % 5 == 0) {
        }
        else {
//            cout << i+1 << endl;
            ans += (i+1);
        }

    }
    cout << ans << endl;

}
