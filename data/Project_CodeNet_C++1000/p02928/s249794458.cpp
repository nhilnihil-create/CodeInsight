#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2002;
const LL MOD = 1e9 + 7;

int n, k, a[N];

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(a[i]>a[j])cnt++;
	LL ans = 1LL * cnt * k % MOD;
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=1;j<=n;j++){
			if(a[i]<a[j])tmp++;
		}
		ans = (ans + 1LL * tmp * (1LL * (k-1) * k / 2 % MOD) % MOD) % MOD;
	}
	/*
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=1;j<=n;j++){
			if(a[i]>a[j])tmp++;
		}
		ans = (ans + 1LL * tmp * (1LL * (k-1) * k / 2 % MOD) % MOD) % MOD;
	}
	*/
	cout << ans << endl;
}
