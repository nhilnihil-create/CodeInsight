#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
const int MX = 300005;
int n, a[MX], b, un[MX], t, av[MX];
int main(){
	scanf("%d", &n);
	rep(i,n){
		scanf("%d", &b);
		a[b-1]++;
	}
	sort(a,a+n, greater<int>());
	un[n] = n; av[n] = 1;
	for(int i = n-1; i > 0; i--){
		for(;a[t] > i; t++);
		un[i] = un[i+1] - t;
		av[i] = un[i] / i;
	}
	av[0] = n;t = n;
	rep(i,n){
		for(; av[t] < i+1; t--);
		printf("%d\n", t);
	}
}