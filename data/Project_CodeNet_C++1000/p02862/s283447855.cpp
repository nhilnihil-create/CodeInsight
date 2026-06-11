//q073.cpp
//Thu Sep  3 22:01:38 2020

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
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

//nCk を1000000007で割った余りの計算。
const ll MAX = 1000010;
ll fac[MAX], finv[MAX], inv[MAX];

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
ll COM(ll n, ll k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
	ll x,y;
	cin >> x >> y;

	ll total = -1;
	ll par = -1;
	for (ll i=0;i<1000010;i++){
		ll a = 1*i;
		ll b = 2*i;
		if (b>y) break;
		if ((x-a)%2==0 && (x-a)/2==y-b){
			total = i+y-b;
			par = i;
			break;
		}
	}

	if (total==-1){
		cout << 0 << endl;
		return 0;
	}

	COMinit();
	cout << COM(total,par) << endl;
}