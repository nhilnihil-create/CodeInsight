#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	int h,n;cin>>h>>n;
	vector<ll> a(n);
	vector<ll> b(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i]>>b[i];
	}
	vector<vector<ll>> dp(h+ 2,vector<ll>(n +1,INF));
	for(int i = 0; i <= n; i++) {
		dp[0][i] = 0;
	}
	for(ll i = 1; i <= h; i++) {
		for(int j = 1; j <= n; j++) {
			if (i - a[j- 1] < 0){
				dp[i][j] = min(dp[i][j - 1],b[j - 1]);
			}
			else{
				dp[i][j] = min(dp[i][j - 1], dp[i - a[j-1]][j] + b[j-1]);
			}
		}
	}
	cout << dp[h][n] << endl;
	return 0;
}