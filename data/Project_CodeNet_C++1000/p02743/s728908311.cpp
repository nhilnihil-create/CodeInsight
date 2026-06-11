//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> a >> b >> c;
	x = 4*a*b;
	y = c-a-b;
	if (y<0) {
		cout << "No" << endl;
		return 0;
	}
	y = y*y;
	if (x < y) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	//vector<ll>	aa(n);
	//for(i=0;i<n;i++) cin >> aa[i];
	//vector<ll>	dp(n+1,INFL);
	//vector<vector<ll>>	dp2(x , vector<ll>(y,INFL));

//	cout << ans << endl;
	return 0;
}
