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

void solve(){
	int h, w;
	cin >> h >> w;
	char maze[h][w];
	int dp[h+1][w+1];
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> maze[i][j];
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(i!=h-1)chmin(dp[i+1][j], dp[i][j]+(maze[i+1][j]!=maze[i][j]));
			if(j!=w-1)chmin(dp[i][j+1], dp[i][j]+(maze[i][j+1]!=maze[i][j]));
		}
	}

	int ans = dp[h-1][w-1]+(maze[0][0]=='#')+(maze[h-1][w-1]=='#');
	cout << ans/2 << endl;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}