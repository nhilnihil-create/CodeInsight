#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 100005;

long long modpow(long long a, long long p){
	if(p == 0)return 1;
  	if(p % 2 == 1)return a * modpow(a, p - 1) % MOD;
  
  	long long r = modpow(a, p / 2);
  	return r * r % MOD;
}

int n, k;
long long cnt[MAXN];

int main(){
	scanf("%d %d", &n, &k);
  	
  	long long res = 0;
  	for(int g = k; g >= 1; g--){
    	cnt[g] = modpow(k / g, n);
      	for(int z = g + g; z <= k; z += g)
        	cnt[g] = (cnt[g] - cnt[z] + MOD) % MOD;
      	res = (res + cnt[g] * g) % MOD;
    }
  	printf("%lld\n", res);
  	
  	return 0;
}