//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y,h2,m2;
	ll		ans = 0;
	string	s;
	cin >> h >> m >> h2 >> m2 >> k;
	a = h*60+m;
	b = h2*60+m2;
	ans = b - a - k;
	//vector<ll>	aa(n);
	//for(i=0;i<n;i++) cin >> aa[i];
	//vector<ll>	dp(n+1,INFL);
	//vector<vector<ll>>	dp2(x , vector<ll>(y,INFL));

	cout << ans << endl;
	return 0;
}
