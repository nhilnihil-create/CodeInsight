#include <iostream>
#include <iomanip>
#include<math.h>
#include<list>
#include <algorithm>
#include<set>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include <numeric>
#include <queue>
#include <sstream>
#include <bitset>
#include<stack>
#include<functional>
#include<unordered_set>
#include<unordered_map>
#include<atcoder/all>

using ll=long long;

using namespace std;
int main()
{
	ll N, Q;
	cin >> N >> Q;

	atcoder::dsu uf(N);
	for (auto i = 0LL; i < Q; i++) {
		ll t, u, v;
		cin >> t >> u >> v;
		if (t == 0) {
			uf.merge(u, v);
		}
		else {
			cout << uf.same(u, v) << endl;
		}
	}
	return 0;
}

