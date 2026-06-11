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
	int n, m;
	cin >> n >> m;
	int dp[m+1][1<<n];
	repn(i,m)rep(j,1<<n) dp[i][j] = INF;
	int a[m];
	vector<int> b[m];
	rep(i,m){
		int q;
		cin >> a[i] >> q;
		rep(j,q){
			int r;
			cin >> r;
			r--;
			b[i].push_back(r);
		}
	}

	dp[0][0] = 0;
	rep(i,m){
		for(int bit = 0; bit < (1 << n); bit++){
			chmin(dp[i+1][bit], dp[i][bit]);
			int nowbit = bit;
			for(auto e : b[i]){
				nowbit = nowbit | 1 << e;
			}
			chmin(dp[i+1][nowbit], dp[i][bit]+a[i]);
		}
	}
	if(dp[m][(1<<n)-1]==INF) cout << -1 << endl;
	else cout << dp[m][(1<<n)-1] << endl;
}