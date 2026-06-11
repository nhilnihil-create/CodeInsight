#include<bits/stdc++.h>
#define ull unsigned long long
#define pi acos(-1)
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f;
const ll maxn = 1e7+5;
const ll mod = 1e9+7;
ll qmi(ll a,ll k,ll mod){//快速幂 算a的k次方 
	ll res=1;
	while(k){
		if(k&1/*判断是否为奇数 */) res=(ll)res*a%mod;
		a=(ll)a*a%mod;
		k>>=1/*实际上将K除以2*/;
	}
	return res;
}
int main(){
	int n;
	cin >> n;
	cout << (qmi(10,n,mod)%mod+qmi(8,n,mod)%mod-2*(qmi(9,n,mod)%mod)%mod+mod)%mod << '\n';
	return 0;
}