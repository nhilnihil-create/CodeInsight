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
template<class T> using pq = priority_queue<T>;
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
const ll MOD = 1e9 + 7;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -MOD * MOD;
const long double pi = 3.141592653589793;
int main() { // 問題文はしっかり読め!!!
	string s;
	cin >> s;
	int n = s.size();
	VV dp(n + 1, V(2, upper)); // i桁目まで支払って、前の桁が繰り上がっていない/いるときの最小の枚数
	dp[0][0] = 0;
	reverse(all(s));
	rep(i, n) {
		rep(j, 2) {
			if (j == 0) { // 前の桁が繰り上がっていないとき
				chmin(dp[i + 1][j], dp[i][j] + (s[i] - '0')); // ぴったり支払う
				chmin(dp[i + 1][j + 1], dp[i][j] + (10 - (s[i] - '0'))); //桁を繰り上げる(店員に支払わせる)
			}
			if (j == 1) { // 前の桁が繰り上がっているとき
				chmin(dp[i + 1][j - 1], dp[i][j] + (s[i] - '0') + 1); // 前の桁の分まで支払う
				chmin(dp[i + 1][j], dp[i][j] + (10 - (s[i] - '0') - 1)); // また後回しにする
			}
		}
	}
	cout << min(dp[n][0], dp[n][1] + 1) << endl;
	return 0;
}