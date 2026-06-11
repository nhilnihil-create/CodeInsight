#include <bits/stdc++.h>
using namespace std;
#define el '\n'
typedef long long ll;
const int MAXN = 1e5+2;
const ll MOD = 1e9+7;
int N, K;
ll F[MAXN], ans;
ll qu_pow(ll base, ll exp){
	if(exp==0)return 1;
	if(exp%2==0){
		ll tmp = qu_pow(base, exp/2)%MOD;
		return (tmp*tmp)%MOD;
	}else{
		ll tmp = qu_pow(base, exp-1)%MOD;
		return (base*tmp)%MOD;
	}
}
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	for(int i = K;i>=1;i--){
		F[i] = qu_pow(K/i, N);
		for(int j = 2*i;j<=K;j+=i){
			F[i]-=F[j];
		}
		ans+=((1LL)*F[i]*i)%MOD;
		ans%=MOD;
	}
	cout << (ans+MOD)%MOD << el;
	return 0;
}