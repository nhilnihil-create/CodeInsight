#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m;
	cin >>n >>m;
	VI s(n), t(m);
	rep(i, n) cin >>s[i];
	rep(i, m) cin >>t[i];
	
	vector<VL> dp(n+5, VL(m+5)), sm(n+5, VL(m+5));
	dp[0][0] = sm[1][1] = 1;
	rep(i, n+1) rep(j, m+1) if(i+j !=0){
		if(i && j && s[i-1] == t[j-1]) dp[i][j] = sm[i][j] % MD;
		sm[i+1][j+1] = (sm[i+1][j] + sm[i][j+1] - sm[i][j] + dp[i][j]+MD)%MD;
	}
	cout << sm[n+1][m+1] <<"\n";
	return 0;
}
