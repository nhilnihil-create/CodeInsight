#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VP vector<pair<int,int>>
#define VPP vector<pair<int,pair<int,int>>>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)
typedef pair <int, int> P;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int  INF = 1 << 30;
const ll INFL = 1LL << 60;
const ll mod = 1000000007;




int main() {

	string s;
	cin >> s;
	reverse(ALL(s));

	int n = s.size();
	VVI dp(n, VI(2));
	dp[0][0] = s[0] - '0';
	dp[0][1] = 11 - dp[0][0];
	FOR(i, 1, n) {
		int k = s[i] - '0';
		dp[i][0] = min(dp[i - 1][0] + k, dp[i - 1][1] + k);
		dp[i][1] = min(dp[i - 1][0] + 11 -k, dp[i - 1][1] + 9 - k);
	}
	cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;


}