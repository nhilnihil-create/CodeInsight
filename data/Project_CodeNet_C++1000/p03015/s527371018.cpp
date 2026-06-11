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
	string l;
	cin >>l;
	
	int n=sz(l);
	VL dp = {1, 0};
	rep(i, n){
		VL np(2);
		// a+b =0
		if(l[i]=='0'){
			np[0] += dp[0];
			np[1] += dp[1];
		}else np[1] += dp[0] + dp[1];
	//a+b =1
		if(l[i]=='0') (np[1] += dp[1] * 2) %=MD;
		else{
			(np[0] += dp[0] * 2) %=MD;
			(np[1] += dp[1] * 2) %=MD;
		}
		swap(dp, np);
	}
	cout << (dp[0] + dp[1]) %MD <<"\n";
	return 0;
}
