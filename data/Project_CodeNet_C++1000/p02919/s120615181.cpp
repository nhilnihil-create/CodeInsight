#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL ll[400005],rr[400005],l[400005],r[400005];
LL stk[400005],tp = 0;
LL n,a[400005],tot = 0;

LL dp[25][400005];
LL LOG[400005];

void init(){
	LOG[0] = -1;
	for(LL i = 1;i <= n;i ++) LOG[i] = LOG[i >> 1] + 1;
	for(LL i = 0;i <= n;i ++) dp[0][i] = a[i];
	for(LL i = 1;i <= 20;i ++){
		for(LL j = 0;j <= n;j ++){
			if(j + (1 << (i - 1)) > n) break;
			dp[i][j] = max(dp[i - 1][j],dp[i - 1][j + (1 << (i - 1))]);
		}
	}
}

LL query(LL x,LL y){
	LL k = LOG[y - x + 1];
	return max(dp[k][x],dp[k][y - (1LL << k) + 1]);
}

int main(){
	cin >> n;
	for(LL i = 1;i <= n;i ++) cin >> a[i];
	for(LL i = 1;i <= n;i ++){
		l[i] = 0;
		r[i] = n + 1;
	}
	l[0] = 0; r[n + 1] = n + 1;
	
	tp = 0;
	for(LL i = 1;i <= n;i ++){
		while(tp && a[stk[tp]] < a[i]){
			r[stk[tp]] = i;
			tp --;
		}
		stk[++ tp] = i;
	}
	
	tp = 0;
	for(LL i = n;i >= 1;i --){
		while(tp && a[stk[tp]] < a[i]){
			l[stk[tp]] = i;
			tp --;
		}
		stk[++ tp] = i;
	}
	
	init();
	for(LL i = 1;i <= n;i ++){
		LL L = 0,R = l[i] - 1,mid,tmp = 0;
		while(L <= R){
			mid = (L + R) >> 1;
			if(query(mid,l[i] - 1) > a[i]){
				tmp = mid;
				L = mid + 1;
			}
			else R = mid - 1;
		}
		ll[i] = tmp;
	}
	for(LL i = 1;i <= n;i ++){
		LL L = r[i] + 1,R = n + 1,mid,tmp = n + 1;
		while(L <= R){
			mid = (L + R) >> 1;
			if(query(r[i] + 1,mid) > a[i]){
				tmp = mid;
				R = mid - 1;
			}
			else L = mid + 1;
		}
		rr[i] = tmp;
	}
	
	for(LL i = 1;i <= n;i ++){
		tot += a[i] * ((rr[i] - r[i]) * (i - l[i]));
		tot += a[i] * ((r[i] - i) * (l[i] - ll[i]));
	}
	
	cout << tot << endl;
	return 0;
}