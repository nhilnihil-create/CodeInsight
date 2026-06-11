#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int mod_pow(int x,int y,int INF) {
    int res = 1;
    while(y > 0) {
        if(y%2) {
            res = res*x%INF;
        }
        x = x*x%INF;
        y/=2;
    }
    return res;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i;
		res %= mod;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)
		return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod ;
}
signed main() {
	int n,a,b;cin>>n>>a>>b;
	int ans=mod_pow(2,n,mod)-1;
	ans-=comb(n,a);ans=(ans+mod)%mod;
	ans-=comb(n,b);ans=(ans+mod)%mod;
	cout<<ans<<endl;
}