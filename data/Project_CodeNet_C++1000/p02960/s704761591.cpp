#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

ll rep_power_modM(ll a, ll n, ll M = MOD){
	if(n == 0)return 1;
	if(n%2 == 0){ll tmp = rep_power_modM(a,n/2,M); return tmp*tmp%M;}
	return a*rep_power_modM(a,n-1,M)%M;
}

int main(){
	string s;
	cin >> s;
	int N = s.size();
	vector<vector<ll>> dp(N+1, vector<ll>(13, 0));
	dp[0][0] = 1;
	rep(i,N)rep(j,13){
		ll ni = i + 1, nj = rep_power_modM(10, N-1-i, 13);
		if(s[i] == '?'){
			rep(nd,10){
				ll rnj = (nj*nd + j) % 13; 
				dp[ni][rnj] += dp[i][j];
				dp[ni][rnj] %= MOD;
			}
		}else{
			ll rnj = (nj*(s[i]-'0') + j) % 13;
			dp[ni][rnj] += dp[i][j];
			dp[ni][rnj] %= MOD;
		}
	}
	//REP(i,N){rep(j,13)cout << dp[i][j]<< ' ';cout << endl;}
	cout << dp[N][5] << endl;
	return 0;
}
