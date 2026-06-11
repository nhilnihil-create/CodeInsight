#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 100005;
int n, c, t;
long long a[MX], x, o, ans, u;
int main(){
	scanf("%d", &n);
	rep(i,n){
		scanf("%lld", a+i);
		x ^= a[i];
		o |= a[i];
	}
	ans += x;
	rep(i,n) a[i] &= ~x;
	o &= ~x;
	for(int i = 60; i >= 0; i--) if(o>>i&1){
		for(c = t; c < n && ~a[c]>>i&1; c++);
		if(c != n){
			swap(a[c], a[t]);
			rep(j,n) if(j != t && a[j]>>i&1) a[j] ^= a[t];
			t++;
		}
	}
	rep(i,n) u ^= a[i];
	printf("%lld\n", ans + u*2);
}