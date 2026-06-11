#include<bits/stdc++.h>
using ll = int_fast64_t;
#define REP(i,b,e) for(ll i=b; i<e; i++)

struct fenwick {
	std::vector<ll> data;
	fenwick(int n): data(n+1, 0) {}

	void add(int idx, ll x){
		idx++;
		while(idx<data.size()){
			data[idx] += x;
			idx += idx & -idx;
		}
	}

	ll _sum(int idx){
		ll ret = 0;
		while(idx>0){
			ret += data[idx];
			idx -= idx & -idx;
		}
		return ret;
	}

	ll sum(int l, int r){
		l++, r++;
		return _sum(r-1) - _sum(l-1);
	}
};


int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	fenwick bit(n);
	REP(i, 0, n){
		ll a;
		scanf("%ld", &a);
		bit.add(i, a);
	}

	REP(i, 0, q){
		ll t, x, y;
		scanf("%ld %ld %ld", &t, &x, &y);
		if(t==0) bit.add(x, y);
		else printf("%ld\n", bit.sum(x, y));
	}
	return 0;
}

