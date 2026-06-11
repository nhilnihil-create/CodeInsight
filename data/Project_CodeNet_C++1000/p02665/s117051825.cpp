#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
int n, cnt, a[100005];
ll ac[100005], t = 1, ans;
int main(){
	scanf("%d", &n);
	rep(i,n+1) scanf("%d", a+i);
	for(int i=n; i>=0; i--) ac[i] = ac[i+1] + a[i];
	rep(i,n+1){
		ans += t;
		t -= a[i];
		if(t < 0) return puts("-1") * 0;
		t = min(t*2, ac[i+1]);
	}
	printf("%lld\n", ans);
}