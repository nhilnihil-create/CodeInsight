#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/
 
 
 
 
 
 
 
 
 
 
 
 
 
 
string N;
int dp[1010101][2];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	reverse(all(N));
 
	int n = N.length();
	rep(i, 0, n + 1) rep(d, 0, 2) dp[i][d] = inf;
	dp[0][0] = 0;
	rep(i, 0, n) rep(d, 0, 2) if (dp[i][d] != inf) {
		int c = N[i] - '0';
 
	
			if (d == 1) c++;
 
			chmin(dp[i + 1][0], dp[i][d] + c);
			chmin(dp[i + 1][1], dp[i][d] + 10 - c);
		
	}
 
	int ans = min(dp[n][0], dp[n][1] + 1);
	cout << ans << endl;
}
 
 
