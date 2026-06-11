#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
ll mod_pow(ll x, ll p){
	ll res=1;
	ll n=x;
	while(p>0){
		if(p&1==1)res=(res*n)%MOD;
		n=(n*n)%MOD;
		p=(p>>1);
	}
	return res;
}

int main() {
    ll N; cin>>N;
    vector<bitset<60>> A(N);
    for (int i = 0; i < N; i++){
        ll a; cin>>a;
        A[i]=a;
    }
    vector<ll> num(60,0);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 60; j++){
            if(A[i][j])num[j]++;
        }
    }
    ll ans=0;
    for (int i = 0; i < 60; i++){
        ll tmp=num[i]*(N-num[i])%MOD;
        tmp*=mod_pow(2,i);
        tmp%=MOD;
        ans+=tmp;
        ans%=MOD;
    }
    cout<<ans<<endl;
}