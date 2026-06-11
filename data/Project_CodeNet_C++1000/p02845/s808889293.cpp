#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
using P = pair<ll, ll>;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using Graph = VV;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Inf = (1 << 30);
ll inf = (1LL << 60);
const int MOD = 1e9 + 7;
int main() {
	int n;
	cin >> n;
	V count(n, 0);
	ll ans = 1;
	rep(i, n) {
		int a;
		cin >> a;
		count[a]++;
		if (i == 0 && a != 0) {
			// cout << "E1" << endl;
			cout << 0 << endl;
			return 0;
		}
		if (count[a] >= 4 || i < a) {
			// cout << "E2" << endl;
			cout << 0 << endl;
			return 0;
		}
		if (a == 0) {
			ans *= 4 - count[a];
			// cout << 3 - count[a] << endl;
		}
		else {
			int tmp = count[a - 1] - count[a];
			if (tmp < 0) {
				cout << 0 << endl;
				return 0;
			}
			tmp++;
			ans *= max(tmp, 0);
			// cout << tmp << endl;
		}
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}