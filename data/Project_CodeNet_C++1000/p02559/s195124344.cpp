#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using ll = long long int;
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

ll bitree[555555];

ll query(int x){
	ll v = 0ll;
	while(x){
		v += bitree[x];
		x -= (x&(-x));
	}
	return v;
}

void update(int x, ll v){
	++x;
	while(x<555555){
		bitree[x] += v;
		x += (x&(-x));
	}
}

int main(void){
	int n,q,i,t,l,r;
	ll a;
	std::cin >> n >> q;
	for(i=0; i<n; ++i){
		std::cin >> a;
		update(i,a);
	}
	for(i=0; i<q; ++i){
		std::cin >> t >> l >> r;
		if(t){
			std::cout << (query(r)-query(l)) << std::endl;
		}else{
			update(l,r);
		}
	}
	return 0;
}
