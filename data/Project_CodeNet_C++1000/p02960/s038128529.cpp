#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
	string s;
	cin >> s;
	vector<vector<ll>> dp(s.length()+5, vector<ll>(13, 0));
	dp[s.length()][0] = 1;
	int a = 1;
	for(int i = s.length(); i > 0; i--){
		if(s[i-1]=='?'){
			for(int j = 0; j < 10; j++){
				for(int k = 0; k < 13; k++){
					dp[i-1][(j*a+k)%13] += dp[i][k];
				}
			}
			for(int j = 0; j < 13; j++){
				dp[i-1][j] %= MOD;
			}
		}else{
			int p = s[i-1] - '0';
			for(int j = 0; j < 13; j++){
				dp[i-1][(p*a+j)%13] += dp[i][j];
			}
			for(int j = 0; j < 13; j++){
				dp[i-1][j] %= MOD;
			}
			
		}
        a = a*10%13;
	}
	cout << dp[0][5] << endl;
}