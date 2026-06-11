#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
const int MAX = 1100000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	ll x,y;
	cin>>x>>y;
	ll ans=0;
    COMinit();

    // 計算例
 //   cout << COM(100000, 50000) << endl;	
	for(ll i=0;i<=x;i++){
		ll nexy=x-i;
	//	cout <<ans<<i<<endl;
		if(nexy%2!=0){
			continue;
		}
		ll zany=y-i*2;
		if(zany<0){
			continue;
		}
		if(zany==nexy/2){
			ans+=COM(zany+i,i);
			ans%=inf;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}