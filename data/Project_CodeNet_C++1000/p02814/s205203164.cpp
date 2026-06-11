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
	VI a(n), b(n);
	rep(i, n) cin >>a[i];
	rep(i, n) b[i] = a[i] / 2;
	ll zz=b[0], ng= 0;
	rep(i, n){
		zz = lcm(zz, b[i]);
		if(zz > m) ng=1;
	}
	ll ans = 0;
	if(m >= zz) ans = 1 + (m-zz)/(2*zz);
	VI ck2(n);
	rep(i ,n){
		int c=0;
		for(int w=a[i]; w>0 && w%2==0; w/=2) c++;
		ck2[i]=c;
	}
	int zm =-1;
	rep(i, n){
		if(ck2[i] >0&& zm==-1) zm=ck2[i];
		if(ck2[i]>0 && zm != ck2[i]) ng=1;
	}
	if(ng) ans =0;
	cout << ans <<"\n";
	/*{
		const int MX=m;
		map<int, int> mp;
		rep(i, n){
			rep(j, MX){
				if(a[i] * j + a[i]/2 > MX) break;
				mp[a[i] * j + a[i]/2]++;
			}
		}
		int as=0;
		for(auto x: mp) if(x.second==n){ as++; }
		dbg("sm=", as);
	}
	*/
	return 0;
}
