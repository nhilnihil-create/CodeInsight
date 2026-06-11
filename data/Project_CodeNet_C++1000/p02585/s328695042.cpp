#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long  ll; typedef vector<int> VI; typedef pair<int,int> pii; typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <class F,class ...S> void dbg(const F& f, const S&...s){cerr <<f <<": "; dbg(s...);}

struct UF{
	vector<int> p;
	UF() {}
	UF(int n) : p(n, -1) {}
	int find(int a){ return p[a] < 0 ? a : p[a] = find(p[a]); }
	bool unite(int a, int b) {
		a = find(a); b = find(b);
		if(a == b) return false;
		if(-p[a] < -p[b]) swap(a, b);
		p[a] += p[b]; p[b] = a;
		return true;
	}
	bool root(int a){ return p[a] < 0; }
	bool same(int a, int b){ return find(a) == find(b); }
	int size(int a){ return -p[find(a)]; }
};

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, k;
	cin >>n >>k;
	VI p(n), c(n);
	rep(i, n){ cin >>p[i]; p[i]--;}
	rep(i, n) cin >>c[i];
	
	UF ufa(n);
	rep(i, n) ufa.unite(i, p[i]);
	
	VL sm(n);
	rep(i, n) sm[ufa.find(i)] += c[i];


	ll ans = -1e17;
	rep(i, n){
		int z =i, cnt =0;
		ll cnd = 0;
		while(1){
			z = p[z];
			if(++cnt > k ) break;
			cnd += c[z];
			ll s = (k-cnt)/ ufa.size(i);
			ll w = max(0LL,sm[ufa.find(i)]) * max(s, 0LL);
			ans = max(ans, cnd + w);
			//dbg(z, cnt,cnd,w, cnd+w);
			if(z == i ) break;
		}
	}
	cout <<ans <<"\n";
	return 0;
}

