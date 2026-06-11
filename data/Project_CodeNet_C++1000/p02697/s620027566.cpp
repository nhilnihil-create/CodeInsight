#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;	
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

const ll INF = 1LL << 61;

#include <bits/stdc++.h>
using namespace std;

const ll mod = 1000000007;


int main() {
	ll n, m;
	cin >> n >> m;
	if (n % 2 == 1) {
		for (int i = 0; i < m; i++) {
			cout << i + 1 << " " << n - i - 1 << endl;
		}
	}
	else {
		vector<bool> dist(n + 1, false);
		for (int i = 0, j = 0; i < m; i++, j++) {
			auto left = i + 1;
			auto right = n - j -1;
			while (true) {
				auto c1 = right - left;
				auto c2 = (left - right + n) % n;
				if (dist[c1] || dist[c2] || (c1==c2)) {
					right--;
					j++;
				}
				else {
					dist[c1] = true;
					dist[c2] = true;
					break;
				}
			}
			cout << left << " " << right << endl;
		}
	}
	return 0;
}
