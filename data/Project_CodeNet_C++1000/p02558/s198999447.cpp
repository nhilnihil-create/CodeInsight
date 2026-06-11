// Code for A - Disjoint Set Union
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
	int N, q;

  cin >> N >> q;

	dsu d(N);

	while(q--){
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0) {
      d.merge(u, v);
    } else {
      cout << d.same(u,v) << endl;
    }
	}
	return 0;
}
