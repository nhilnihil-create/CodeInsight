#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAXN 2010
ll C[MAXN][MAXN];
const ll mod = 1e9+7;
void init(){
	C[0][0] = 1;
	C[1][0] = 1;
	C[1][1] = 1;
	for(int i=2; i<MAXN; ++i){
		C[i][0] = 1;
		for(int j=1; j<MAXN; ++j)
			C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
	}
}

int main(){
	init();
	ll n, b, r;
	cin >> n >> b;
	r = n-b;
	for(ll i=1; i<=b; ++i){
		ll r1 = C[r+1][i];
		ll r2 = C[b-1][i-1]; 
		cout << (r1*r2)%mod << endl;
	}
}
