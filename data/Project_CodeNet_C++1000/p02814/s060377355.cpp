#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
	ll gcd(ll x, ll y){ return y? gcd(y, x%y): x; }
	ll lcm(ll x, ll y){ return (x  / gcd(x, y) * y ); }

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m;
	cin >>n >>m;
	VI a(n);
	rep(i, n) cin >>a[i];
	ll zz=a[0]; int ng= 0, zm=-1;
	rep(i, n){
		zz = lcm(zz, a[i]);
		if(zz > 2LL*m){ ng=1; break;}
		int c=0;
		for(int w=a[i]; w>0 && w%2==0; w/=2) c++;
		if(zm ==-1 && c>0) zm=c;
		if(zm !=-1 && c>0 && zm !=c){ ng=1; break;}
	}
	ll ans = 0;
	if(2LL*m >= zz) ans = 1 + (m-zz/2)/zz;

	if(ng) ans =0;
	cout << ans <<"\n";

	return 0;
}
