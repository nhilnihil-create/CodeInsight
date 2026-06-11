#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

ll dp[(1<<12)];
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	vector<vector<int>> c(m,vector<int>(0));

	rep(i,m){
		cin >> a[i] >> b[i];
		rep(j,b[i]){
			int x;
			cin >> x;
			--x;
			c[i].push_back(x);
		}
	}
	rep(i, (1<<12)){
		dp[i] = 1e9;
	}
	dp[0] = 0;
	rep(mask,(1 << n)){
		rep(j,m){
			// 鍵 j を使う
			ll nextmask = mask;
			rep(i,c[j].size()){
				nextmask = nextmask | (1 << c[j][i]);
			}
			chmin(dp[nextmask], dp[mask] + a[j]);
		}
	}
	ll ans = dp[(1 << n)-1];
	cout << (ans == 1e9 ? -1: ans) << endl;
}
