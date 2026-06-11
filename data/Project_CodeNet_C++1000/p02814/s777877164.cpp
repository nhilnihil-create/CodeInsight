#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

ll gcd(ll i, ll j) { return i % j ? gcd(j, i % j) : j; }

int main() {

	int n, m;
	cin >> n >> m;
	int p = 0;
	ll lcm = 1;
	vi a(n);
	rep(i, n)cin >> a[i];
	
	rep(i,n){
		int p2 = 0;
		int aa = a[i];
		while (!(aa & 1)) {
			aa /= 2;
			p2++;
		}

		aa = a[i] / 2;
		
		if (i == 0) {
			p = p2;
			lcm = aa;
		}
		else if (p2 != p) {
			cout << 0 << endl;
			return 0;
		}
		else {
			lcm = aa / gcd(lcm, aa) * lcm;
			if (lcm > m) {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	cout << (m - lcm) / (2 * lcm) + 1 << endl;

}