#include<bits/stdc++.h>
using ll = int_fast64_t;
#define REP(i,b,e) for(ll i=b; i<e; i++)

template<typename T>
struct Fenwick {
    std::vector<T> data;
    Fenwick(int sz=1e5): data(sz+1, 0) {}

    void add(int idx, T x){
		idx++;
		while(idx<data.size()){
	    	data[idx] += x;
	    	idx += idx & -idx;
		}
    }

	T __sum(int r){
		T ret = 0;
		while(r>0){
			ret += data[r];
			r -= r & -r;
		}
		return ret;
	}

	T sum(int l, int r){
		return __sum(r+1) - __sum(l);
	}

};


int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	Fenwick<ll> bit(n);
	REP(i, 0, n){
		ll a;
		scanf("%ld", &a);
		bit.add(i, a);
	}

	REP(i, 0, q){
		ll t, x, y;
		scanf("%ld %ld %ld", &t, &x, &y);
		if(t==0) bit.add(x, y);
		else printf("%ld\n", bit.sum(x, y-1));
	}
	return 0;
}

