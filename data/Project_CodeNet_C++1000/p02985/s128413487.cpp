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

vector<int64_t> fct, inv;
void finit(int cmx, ll mod =MD){
	fct.resize(cmx+20); inv.resize(cmx+20);
	fct[0] = fct[1] = inv[1] = inv[cmx] = 1;
	for(int i=2;i<cmx+3;i++) fct[i] = fct[i-1] * i % mod;
	for(ll x=fct[cmx], n=mod-2; n > 0; n >>=1, x = x*x %mod)
		if(n & 1) inv[cmx] = inv[cmx] * x %mod;
	for(int i=cmx;i>=1;i--) inv[i-1] = inv[i] * i % mod;
}
ll nPk(ll n, ll k, ll mod =MD) {
	if(k > n || n <0 || k <0) return 0;
	ll ret =fct[n] * inv[n-k] % mod;
	return ret;
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, k;
	cin >>n >>k;
	vector<VL> r(n);
	finit(k+1000);
	rep(i, n-1){
		int a, b; cin >>a >>b;
		r[a-1].push_back(b-1);
		r[b-1].push_back(a-1);
	}
	VL dst(n);
	dst[0] = nPk(k, sz(r[0]) +1);
	
	auto dfs =[&](auto dfs, int c, int p =-1)->void{
		dbg(c, p);
		for(auto v: r[c]) if(v != p ){
			dst[v] = nPk(k-2, sz(r[v]) -1);
			dfs(dfs, v, c);
		}
	};
	
	dfs(dfs, 0);
	ll ans = 1LL;
	for(auto z: dst) (ans *= z) %=MD;
	cout << ans <<"\n";
	return 0;
}
