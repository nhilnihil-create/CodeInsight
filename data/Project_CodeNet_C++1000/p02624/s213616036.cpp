#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
ll ans = 1, v[10000005];
int n, p[10000005];
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++) v[i] = p[i] = i; 
	for(int t=2; t<=n; t++){
		if(p[t] != 1){
			ans += 2 * t;
			for(int s=t*2; s<=n; s+=t){
				for(ll vi = v[s]; p[s] % t == 0; p[s] /= t, v[s] += vi);
			}
		}else ans += v[t];
	}
	printf("%lld\n", ans);
}