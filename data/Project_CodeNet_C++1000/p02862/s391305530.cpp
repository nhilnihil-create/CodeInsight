#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
vector<ll> fact(1000000);
void init_fact(int n){
	fact[0]=1;
	for (int i = 1; i < n+1; i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
}

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
ll nCr(int n, int r){
	ll res=1;
	res*=fact[n];
	res*=mod_pow(fact[r],MOD-2);
	res%=MOD;
	res*=mod_pow(fact[n-r],MOD-2);
	res%=MOD;
	return res;
}
int main() {
    int X,Y; cin>>X>>Y;
    if((X+Y)%3!=0){
        cout<<0<<endl;
        return 0;
    }
    int n=(X+Y)/3;
    int a=2*n-X;
    int b=n-a;
    init_fact(n);
    if(a<0 || b<0){
        cout<<0<<endl;
        return 0;
    }
    cout<<nCr(n,a)<<endl;
}