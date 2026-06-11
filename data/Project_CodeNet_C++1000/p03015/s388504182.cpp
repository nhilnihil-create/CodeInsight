#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

const ll mod = 1e9+7;
//const ll mod = 998244353;
ll dp[100100][2];
int main()
{
	string s;
	cin >> s;

	dp[0][0] = 1;
	For(i,1,s.size()+1){
		// dp[i] を作っていく。
		// ＝への遷移
		if(s[i-1] == '0'){
			// 両方0 
			dp[i][0] += dp[i-1][0];
		} else {
			// どちらを1にするか
			dp[i][0] += dp[i-1][0] * 2;
		}

		// 未満への遷移
		if(s[i-1] == '1'){
			// ＝から,両方0にすることで小さくなる
			dp[i][1] += dp[i-1][0];

			dp[i][1] += dp[i-1][1] * 3;
		} else {
			// 0 0 にしても＝から未満になることはない
			dp[i][1] += dp[i-1][1] * 3;
		}
		dp[i][0] %= mod;
		dp[i][1] %= mod;
	}
	int n = s.size();
	ll ans = dp[n][0] + dp[n][1];
	ans %= mod;
	cout << ans << endl;
}
