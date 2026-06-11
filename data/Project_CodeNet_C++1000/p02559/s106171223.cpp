#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<array>
#include<cassert>
#include <atcoder/fenwicktree>
using namespace std;
#define INF ((1<<30)-1)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	atcoder::fenwick_tree<int64_t> fenwick(n);
	rep(i, n) {
		int a;
		cin >> a;
		fenwick.add(i, a);
	}

	rep(i, q) {
		int t;
		cin >> t;
		if (t == 0) {
			int p, x;
			cin >> p >> x;
			fenwick.add(p, x);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << fenwick.sum(l, r) << endl;
		}
	}


	return 0;
}
