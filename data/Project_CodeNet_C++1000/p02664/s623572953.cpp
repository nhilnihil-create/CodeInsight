//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	t;
	cin >> t;

	n = t.size();
	for(i=0;i<n;i++) {
		if (t[i]=='?') t[i]='D';
	}



	cout << t << endl;
	return 0;
}
