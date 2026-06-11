#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

#define M 1000000007
#define MAX 100005

ll mpow(ll x, ll n){ 
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}
ll msub(ll a,ll b){
	if(a>=b){
		return a-b;
	}
	return msub(a+M,b);
}

int main() {
	ll N,K;
    cin >> N >> K;
	ll gcd_num[MAX];
	
	ll sum=0;
	for(ll i=K; i >0; i--){
		ll num = mpow(K/i,N);
		for(int j=2;i*j<=K;j++){
			num = msub(num,gcd_num[i*j]);
		}
		gcd_num[i] = num;
		sum = (sum + (i * num%M))%M;
	}
	cout << sum << endl;

    return 0;
}
