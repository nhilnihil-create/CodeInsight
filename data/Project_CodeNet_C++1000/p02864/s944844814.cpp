#include <bits/stdc++.h>
using namespace std;
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w

#define int long long
//using ll = long long;
using P = pair<int,int>;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,K,h[310],dp[310][310][310];
	vector<int> hs;
	cin >> n >> K;
	for(int i = 0;i < n;i++){
		cin >> h[i];
		hs.push_back(h[i]);
	}
	hs.push_back(0);
	sort(all(hs));
	hs.erase(unique(all(hs)),hs.end());
	for(int i = 0;i <= n;i++){
		for(int j = 0;j < hs.size();j++){
			for(int k = 0;k <= K;k++) dp[i][j][k] = INF;
		}
	}
	dp[0][0][0] = 0;
	for(int i = 0;i < n;i++){
		for(int k = 0;k <= K;k++){
			int mi = INF;
			for(int j = 0;j < hs.size();j++){
				chmin(mi,dp[i][j][k] - hs[j]);
				chmin(dp[i + 1][j][k + (hs[j] != h[i])],mi + hs[j]);
			}
			mi = INF;
			for(int j = hs.size() - 1;j >= 0;j--){
				chmin(dp[i + 1][j][k + (hs[j] != h[i])],mi);
				chmin(mi,dp[i][j][k]);
			}
		}
	}
	int ans = INF;
	for(int i = 0;i < hs.size();i++){
		for(int j = 0;j <= K;j++) chmin(ans,dp[n][i][j]);
	}
	cout << ans << endl;
}
