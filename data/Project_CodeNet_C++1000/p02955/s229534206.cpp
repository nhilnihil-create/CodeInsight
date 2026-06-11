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
	int n, k;
	cin >>n >>k;
	VI a(n);
	rep(i, n) cin >>a[i];
	
	ll sm = accumulate(all(a), 0LL);
	VI dv;
	for(ll i=1; i*i <=sm; i++){
		if(sm % i ==0){
			dv.push_back(i);
			if(i*i != sm)dv.push_back(sm/i);
		}
	}
	sort(dv.rbegin(), dv.rend());

	for(auto cn: dv){
		VI b(n);
		ll sm = 0, sm2 =0;
		rep(i, n) b[i] = a[i]%cn;
		sort(all(b));
		rep(i, n) sm +=  (cn - b[i])%cn;
		if(sm <= k){ cout <<cn <<"\n"; return 0;}
		rep(i, n){
			sm  -= (cn - b[i])%cn;
			sm2 += b[i];
			if(max(sm, sm2) <= k){ cout <<cn <<"\n"; return 0;}
		}
	
	}
	
	
	return 0;
	
}
