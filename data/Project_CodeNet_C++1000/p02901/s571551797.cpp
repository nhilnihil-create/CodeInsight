#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }

const double PI = acos(-1);
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m;
	cin >>n >>m;
	
	VI a(m), c(m);
	rep(i, m){
		int b, z;
		cin >> a[i] >>b;
		rep(j, b){
			cin >>z; c[i] |= 1<<(z-1);
		}
	}
	VI dp(1<<n, MD); dp[0] = 0;
	rep(i, m) rep(j, 1<<n) if(dp[j]<MD){
		int nj = j | c[i];
		dp[nj] = min(dp[nj], dp[j]+a[i]);
	}
	int ans = dp[(1<<n) -1];
	cout << (ans==MD? -1: ans )<<"\n";
	return 0;
	
}
