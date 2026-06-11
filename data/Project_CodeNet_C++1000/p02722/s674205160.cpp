#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	ll n;
	cin >> n;

	V<ll> div1, divn;
	rep1(i, sqrt(n)) {
		if ((n - 1) % i == 0) {
			if (i != 1)div1.push_back(i);
			if (i * i != n - 1)div1.push_back((n - 1) / i);
		}
		if (n % i == 0) {
			if (i != 1)divn.push_back(i);
			if (i * i != n)divn.push_back(n / i);
		}
	}

	sort(all(div1));
	sort(all(divn));

	ll cnt = div1.size();
	for (auto x : divn) {
		ll nn = n;
		while (nn % x == 0)nn /= x;
		if (nn % x == 1)cnt++;
	}

	cout << cnt << endl;

}