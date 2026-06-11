#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
template<class T> using VE = vector<T>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
int main(){
	string s;
	cin >> s;
	deque<char> dq;
	int n = s.size();
	rep(i, n) dq.push_back(s[i]);
	bool rev = false;
	int q;
	cin >> q;
	rep(qqq, q) {
		int k;
		cin >> k;
		if (k == 1) rev ^= true;
		else {
			int x; char c;
			cin >> x >> c;
			if (rev) x = 3 - x;
			if (x == 1) dq.push_front(c);
			else dq.push_back(c);
		}
	}
	if (rev) {
		while (!dq.empty()) {
			cout << dq.back();
			dq.pop_back();
		}
	}
	else {
		while (!dq.empty()) {
			cout << dq.front();
			dq.pop_front();
		}
	}
	cout << endl;
	return 0;
}