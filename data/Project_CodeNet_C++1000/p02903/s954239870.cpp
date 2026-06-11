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
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	int h1 = h - b;
	int w1 = w - a;
	for (int i = 1; i <= h1; i++) {
		for (int j = 1; j <= w1; j++) {
			cout << 1;
		}
		for (int j = w1 + 1; j <= w; j++) {
			cout << 0;
		}
		cout << endl;
	}
	for (int i = h1 + 1; i <= h; i++) {
		for (int j = 1; j <= w1; j++) {
			cout << 0;
		}
		for (int j = w1 + 1; j <= w; j++) {
			cout << 1;
		}
		cout << endl;
	}
	return 0;
}