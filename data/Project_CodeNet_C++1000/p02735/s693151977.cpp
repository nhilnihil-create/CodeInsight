#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i=0; i<(long long)(n); i++)
#define REP(i, k, n) for(long long i=(long long)(k); i<(long long)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define PQ(T) priority_queue<T>
#define PQS(T) priority_queue<T, vector<T>, greater<T> >
#define deci cout << fixed << setprecision(15);
typedef long long ll;
const ll inf = 1020304050607080910;
const ll mod = 1000000007;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmin(T&x,T y){if(x>y){x=y;return true;}return false;}
template<class T> bool chmax(T&x,T y){if(x<y){x=y;return true;}return false;}
ll gcd(ll x,ll y){if(x>y)swap(x, y);while(x!=0){y%=x;swap(x, y);}return y;}
ll mpow(ll x,ll r){if(r==0)return 1;if(r%2==1){return x*mpow(x,r-1)%mod;}else{ll aa=mpow(x,r/2);return aa*aa%mod;}}

int main(){
	int H, W; cin >> H >> W;
	char s[H][W];
	rep(i, H)rep(j, W) cin >> s[i][j];
	int dp[H][W];
	if(s[H-1][W-1] == '#') dp[H-1][W-1] = 2;
	else dp[H-1][W-1] = 0;
	for(int i=H-1; i>=0; i--){
		for(int j=W-1; j>=0; j--){
			if(i+j==H+W-2) continue;
			if(i==H-1){
				if(s[i][j] == '#' && s[i][j+1] == '.') dp[i][j] = dp[i][j+1] + 2;
				else dp[i][j] = dp[i][j+1];
			}else if(j==W-1){
				if(s[i][j] == '#' && s[i+1][j] == '.') dp[i][j] = dp[i+1][j] + 2;
				else dp[i][j] = dp[i+1][j];
			}else{
				dp[i][j] = 1e9;
				if(s[i][j] == '#' && s[i+1][j] == '.') chmin(dp[i][j], dp[i+1][j]+2);
				else chmin(dp[i][j], dp[i+1][j]);
				if(s[i][j] == '#' && s[i][j+1] == '.') chmin(dp[i][j], dp[i][j+1]+2);
				else chmin(dp[i][j], dp[i][j+1]);
			}
		}
	}
	cout << dp[0][0]/2 << endl;
	return 0;
}

