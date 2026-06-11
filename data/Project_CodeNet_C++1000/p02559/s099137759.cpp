#include<bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;

ll op(ll a, ll b) {return a + b;}
ll e(){return 0LL;}

int main()
{
	int N, Q; cin >> N >> Q;
	vector<ll> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	atcoder::segtree<ll, op, e> tree(A);

	while(Q--) {
		int t, l, r; cin >> t >> l >> r;
		if(t == 0) {
			tree.set(l, r + tree.get(l));
		} else {
			cout << tree.prod(l, r) << endl;
		}
	}
}