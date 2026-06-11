#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<queue>
#include<iomanip>
#include<bitset>
#include<math.h>
#include<stack>
#include<set>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	vector<int> q(a);
	vector<int> w(b);
	vector<int> e(c);
	for (int i = 0; i < a; i++) {
		cin >> q[i];
	}
	for (int j = 0; j < b; j++) {
		cin >> w[j];
	}
	for (int i = 0; i < c; i++) {
		cin >> e[i];
	}
	sort(q.begin(), q.end());
	reverse(q.begin(), q.end());

	sort(w.begin(), w.end());
	reverse(w.begin(), w.end());

	sort(e.begin(), e.end());
	reverse(e.begin(), e.end());
	multiset<int> ne;
	for (int i = 0; i < x; i++) {
		ne.insert(q[i]);
	}
	for (int i = 0; i < y; i++) {
		ne.insert(w[i]);
	}
	for (int i = 0; i < c; i++) {
		if (*ne.begin() < e[i]) {
			ne.erase(ne.begin());
			ne.insert(e[i]);
		}
	}
	int sum = 0;
	for (auto it = ne.begin(); it != ne.end(); it++) {
		sum += *it;
	}
	cout << sum;
}
	