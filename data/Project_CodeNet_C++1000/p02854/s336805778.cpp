#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using pq = priority_queue<int>;
template<class T>
using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int under = (1 << 31);
int upper = under - 1;
ll UNDER = (1LL << 63);
ll UPPER = UNDER - 1;
const int MOD = 1e9 + 7;
const long double pi = 3.141592653589793;
ll fac[110000];
ll finv[110000];
ll inv[110000];
int main() {
	int n;
	cin >> n;
	VL a(n + 1);
	VL sum(n + 1, 0);
	rep1(i, n) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	VL diff(n + 1, 0);
	diff[0] = UPPER;
	rep1(i, n) {
		ll l = sum[i];
		ll r = sum[n] - l;
		diff[i] = abs(l - r);
	}
	cout << *min_element(all(diff)) << endl;
	return 0;
}