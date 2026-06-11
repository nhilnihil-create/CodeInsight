#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int N, Q; cin>>N>>Q;

	fenwick_tree<int64_t> fw(N);

	rep(i, N){
		int a; cin>>a;
		fw.add(i, a); // init: A[i] += a
	}

	rep(i, Q){
		int t, a, b; cin>>t>>a>>b;
		if(t) cout<< fw.sum(a, b) <<endl; // sum(l, r): sum(A[l, r-1])
		else fw.add(a, b); // update(p, x): A[p] += x
	}
}
