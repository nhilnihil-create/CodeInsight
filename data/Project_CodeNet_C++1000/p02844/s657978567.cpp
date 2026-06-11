#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll sum = 0;
	for (int i = 0; i < 1000; i++) {
		int t = i % 10;
		int cache = i;
		int c = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (s[j] - '0' == t) {
				c++;
				cache /= 10;
				t = cache % 10;
				if (c == 3) {
					sum++;
					break;
				}
			}
			if (c == 3) {
				break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
