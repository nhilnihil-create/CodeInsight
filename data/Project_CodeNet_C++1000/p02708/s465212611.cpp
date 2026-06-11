#include <bits/stdc++.h>

using namespace std;

int n,K;
long long ans;
int mod = 1e9 + 7;

int main(){
	scanf("%d%d",&n,&K);
	for(int i=K;i<=n+1;i++){
		long long mi = (long long)(i-1)*i/2LL;
		long long ma = (long long)(n-i+1 + n)*i/2LL;

		ans += ma-mi+1;
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}