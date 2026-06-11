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


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	string s; cin >>s;
	int n = sz(s);
	VL dp(13); dp[0] =1;
	rep(i, n){
		VL np(13);
		int d = (s[i] =='?')?  99: s[i]-'0';
		rep(j, 13){
			if(d< 10) ( np[(j*10+d)%13] +=dp[j] ) %=MD;
			else  rep(k, 10) (np[(j*10+k)%13] += dp[j])%=MD;
		}
		swap(dp, np);
	}
	
	//for(auto x :dp) cerr<<x<<" "; dbg();
	cout << dp[5] <<"\n";
	
	return 0;
	
}
