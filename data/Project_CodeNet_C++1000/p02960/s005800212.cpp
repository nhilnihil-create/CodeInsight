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
ll dp[100010][13];
int main()
{
	string s;
	cin >> s;
	REV(s);

	ll ten = 1;
	dp[0][0] = 1;
	rep(i,s.size()){
		if (s[i] == '?') {
			rep(k,10){
				ll tmp = (ten * k) % 13;
				rep(j,13){
					ll next = (j + tmp) % 13;
					dp[i+1][next] += dp[i][j];
					dp[i+1][next] %= mod;
				}
			}
		}	else {
			int num = s[i] - '0';
			ll tmp = (ten * num) % 13;
			rep(j,13){
				ll next = (j + tmp) % 13;
				dp[i+1][next] += dp[i][j];
				dp[i+1][next] %= mod;
			}
		}
		ten *= 10; ten %= 13;
	}
	ll sum = 0;
	rep(i,13){
		sum += dp[s.size()][i];
	}
	cout << dp[s.size()][5] << endl;
}
