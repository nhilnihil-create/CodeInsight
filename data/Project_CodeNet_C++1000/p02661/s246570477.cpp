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
	int n;
	cin >>n;
	VI a(n), b(n);
	rep(i, n) cin >>a[i] >>b[i];
	sort(all(a)); sort(all(b));
	
	if(n%2){
		cout << (ll)b[n/2] - a[n/2] +1 <<"\n";
	}else{
		cout << ((ll)b[n/2] + b[n/2-1] - a[n/2] -a[n/2-1])  +1 <<"\n";
	}

	return 0;
}
