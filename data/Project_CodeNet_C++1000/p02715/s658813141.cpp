//abc162_e.cpp
//Thu May 14 21:30:18 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007

using namespace std;
using ll=long long;
typedef pair<int,int> P;

ll mod_pow(ll x, ll n){
	ll res = 1;
	while (n>0){
		if (n&1){
			res = res * x % MOD;
		}
		x = x*x%MOD;
		n >>= 1;
	}
	return res;
}

int main(){
	ll n,k;
	cin >> n >> k;

	ll ans = 0;
	ll comb[k+1];
	fill(comb,comb+k+1,0);
	for (int i=k;i>=1;i--){
		ll baisu = k/i;
		comb[i] = mod_pow(baisu,n);
		for (int j=2;j<=baisu;j++){
			comb[i] = (comb[i]-comb[i*j]+MOD)%MOD;
		}
		ans = (ans + comb[i]*i)%MOD;
	}

	cout << ans << endl;

}