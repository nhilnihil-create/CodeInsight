#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef int64_t ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, p; string s;
	cin >>n >>p >>s;
	ll ans = 0;
	if(p==2 || p==5){
		rep(i, n) if((s[i]-'0')%p==0) ans +=i+1;
		cout << ans <<"\n"; return 0;
	}
	VL ct(p); ll ks=1, cr=0; ct[0]=1;
	repr(i, n-1, 0){
		int d = s[i]-'0';
		cr = (d * ks + cr) % p;
		ans += ct[cr];
		ct[cr]++;
		ks = ks * 10 % p;
	}
	cout << ans <<"\n";
	return 0;
}
