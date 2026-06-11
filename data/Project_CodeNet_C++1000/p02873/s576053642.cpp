//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,i,j,k,n,m,x,y,ans = 0;
	string	s;

	cin >> s;
	n = s.size();
	vector<ll> A(n+1, -1);
	a = 0;
	for(i=0;i<n;i++) {
		if (s[i]=='<') A[i] = a++;
		else a = 0;
	}
	a = 0;
	for(i=n-1;i>=0;i--) {
		if (s[i]=='>') A[i+1] = a++;
		else a = 0;
	}
	if (A[0]==-1) A[0] = A[1]+1;
	if (A[n]==-1) A[n] = A[n-1]+1;
	for(i=1;i<n;i++) {
		if (A[i]==-1) A[i] = max(A[i-1],A[i+1]) + 1;
	}
	for(i=0;i<=n;i++) {
		ans += A[i];
	}
 
	cout << ans << endl;
	return 0;
}
