#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(),(x).end()
 
using namespace std;
using ll = long long;
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

struct edge { int to; int cost; };
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1.0e-12;
const double PI = acos(-1.0);
 
const int mx4[] = {0,1,0,-1};
const int my4[] = {1,0,-1,0};
const int mx8[] = {0,1,1,1,0,-1,-1,-1};
const int my8[] = {1,1,0,-1,-1,-1,0,1};

int dp[3010][3010];

int main(){
	int n,t;
	cin >> n >> t;
	vector<P> ab(n);
	rep(i,n) cin >> ab[i].first >> ab[i].second;
	sort(all(ab));
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= t; j++){
			// 食べない場合
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			// 食べる場合
			if(j == t) continue; // もう食べれない
			dp[i+1][min(j+ab[i].first,t)] = max(dp[i+1][min(j+ab[i].first,t)],dp[i][j]+ab[i].second);
		}
	}
	cout << dp[n][t] << endl;

	return 0;
}