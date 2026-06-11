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
	VI a(n);
	rep(i, n) cin >>a[i];
	sort(all(a));
	const int MX = a.back();
	VI ck(MX+100);
	rep2(i, 2, MX+1){
		rep(j, n){
			if((ll)a[j]*i > MX) break;
			ck[a[j]*i ]++;
		}
	}
	rep(i, n-1) if(a[i] == a[i+1]) ck[a[i]]++;

	int ans =0;
	rep(i, n) if(ck[a[i]]==0) ans++;
	cout <<ans <<'\n';
	return 0;
}
