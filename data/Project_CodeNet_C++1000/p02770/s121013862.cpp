#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int k, q, d[5005], n, m;
long long x, sm, cnt;
int main(){
	scanf("%d%d", &k, &q);
	rep(i,k) scanf("%d", d+i);
	rep(o,q){
		scanf("%d%lld%d", &n, &x, &m);
		cnt = sm = 0; x %= m;
		rep(i,k){
			if(i==(n-1)%k) x += sm;
			sm += (d[i] + m - 1) % m + 1;
		}
		cnt += (n-1) / k * (sm / m); sm %= m;
		cnt += ((n-1) / k * sm + x) / m;
		printf("%lld\n", n-1-cnt);
	}
}