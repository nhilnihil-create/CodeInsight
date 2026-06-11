#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

int a[575][575];

void solve(int l, int r, int k){
	int i,j,m;
	if(r-l<2){
		return;
	}
	m = (l+r)/2;
	for(i=l; i<m; ++i){
		for(j=m; j<r; ++j){
			a[i][j] = k;
		}
	}
	solve(l,m,k+1);
	solve(m,r,k+1);
}

int main(void){
	int n,i,j;
	cin >> n;
	solve(0,n,1);
	--n;
	for(i=0; i<n; ++i){
		for(j=(i+1); j<=n; ++j){
			cout << a[i][j] << ((j<n)?" ":"");
		}
		cout << endl;
	}
	return 0;
}
