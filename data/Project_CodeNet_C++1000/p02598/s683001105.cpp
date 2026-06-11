#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int n, k, a[200005], l=0, r=1e9, m;
int main(){
	scanf("%d%d", &n, &k);
	rep(i,n) scanf("%d", a+i);
	while(l+1 < r){
		m = (l+r) / 2;
		long long c = 0;
		rep(i,n) c += (a[i]-1) / m;
		(c <= k ? r : l) = m;
	}
	printf("%d\n", r);
}