#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
int n, m, k, ans;
ll a[200005], b, c;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	rep(i,n){
		scanf("%d", a+i+1);
		a[i+1] += a[i];
	}
	rep(i,m+1){
		if(i) scanf("%d", &c);
		b += c;
		if(b > k) break;
		for(; n>0 && a[n]+b>k; n--);
		ans = max(ans,n+i);
	}
	printf("%d\n", ans);
}