//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		b=0,c=0,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> n;
	vector<ll>	a(n),d(n);
	for(i=0;i<n;i++) cin >> a[i];
	for(i=0;i<n;i+=2) b += a[i];
	for(i=1;i<n;i+=2) c += a[i];
	d[0] = abs(b-c);
	for(i=1;i<n;i++) {
		d[i] = (a[i-1]-d[i-1]/2)*2;
	}
	for(i=0;i<n;i++) cout << d[i] << " ";
	cout << endl;
	return 0;
}
