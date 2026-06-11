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
	cin >> k >> x;
	for(i=x-k+1;i<x+k;i++) {
		if (i<-1000000) i= -1000000;
		if (i>1000000) break;
		cout << i << " ";
	}
	cout << endl;
	
	return 0;
}
