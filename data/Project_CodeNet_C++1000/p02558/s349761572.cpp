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

int ufr[225816],ufp[225816];

void ufinit(int n){
	int i;
	for(i=0; i<n; ++i){
		ufp[i] = i;
		ufr[i] = 1;
	}
}

int ufind(int x){
	if(x == ufp[x]){
		return x;
	}
	return ufp[x] = ufind(ufp[x]);
}

void unionf(int x, int y){
	x = ufind(x);
	y = ufind(y);
	if(x == y){
		return;
	}
	if(ufr[x] < ufr[y]){
		std::swap(x,y);
	}
	ufp[y] = x;
	ufr[x] += ufr[y];
}

int main(void){
	int n,q,i,t,u,v;
	std::cin >> n >> q;
	ufinit(n);
	for(i=0; i<q; ++i){
		std::cin >> t >> u >> v;
		if(t){
			std::cout << (ufind(u)==ufind(v)) << std::endl;
		}else{
			unionf(u,v);
		}
	}
	return 0;
}
