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
	double a, b, h, m;
	cin >>a >>b >>h >>m;
	
	const double PI = acos(-1);
	double fn = m /60.0 ;
	double jk = (h + m/60.0)/12.0;
	
	double x1 = a*cos(fn * PI *2);
	double y1 = a*sin(fn * PI *2);
	double x2 = b*cos(jk * PI *2);
	double y2 = b*sin(jk * PI *2);
	
	double ans = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	cout <<setprecision(15) << ans <<"\n";
	return 0;
}
