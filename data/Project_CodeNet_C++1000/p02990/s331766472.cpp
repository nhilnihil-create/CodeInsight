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

vector<vector<ll>> cmb(2050, vector<ll>(2050));
void mkcmb(const int MX){
	rep(i,MX+1)  cmb[i][0] = 1;
	rep2(i,1,MX+1) rep2(j,1,i+1)
		cmb[i][j] = (cmb[i-1][j] + cmb[i-1][j-1])%MD;
}

ll ncr(ll n, ll k){
	if(k > n || n <0 || k <0) return 0;
	return cmb[n][k];
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, k;
	cin >>n >>k;
	
	mkcmb(2045);
	rep2(i, 1, k+1){
		ll z1 = ncr(n-k+1, i) * ncr(k-1, i-1);
		cout << z1%MD <<"\n";
	}
	
	return 0;
}
