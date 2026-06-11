#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long  ll; typedef vector<int> VI; typedef pair<int,int> pii; typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <class F,class ...S> void dbg(const F& f, const S&...s){cerr <<f <<": "; dbg(s...);}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; ll k;
	cin >>n >>k;
	VI a(n);
	rep(i, n){ cin >>a[i]; a[i]--;}
	int cr =0;
	while(k>0){
		if(k&1) cr =a[cr];
		VI na(n);
		rep(i, n) na[i] = a[a[i]];
		swap(a, na);
		k >>= 1;
	}
	cout <<cr +1 <<"\n";
	return 0;
}
