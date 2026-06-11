#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int n;
long long x[105], y[105], id[205];
long double ans;
int main(){
	scanf("%d", &n);
	rep(i,n){
		scanf("%lld%lld", x+i, y+i);
		id[i] = i;
	}
	sort(id, id+n, [](int a, int b){return atan2(x[a],y[a]) > atan2(x[b], y[b]);});
	rep(i,n) id[i+n] = id[i];
	rep(i,n){
		long double ax = 0, ay = 0;
		for(int j = i; j < i+n && x[id[i]] * y[id[j]] - y[id[i]] * x[id[j]] >= 0; j++){
			ax += x[id[j]]; ay += y[id[j]];
			ans = max(ans,hypot(ax,ay));
		}
	}
	printf("%.20Lf\n", ans);
}