#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int main() {
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	vector<int> p(a), q(b), r(c);
	for (int i = 0; i < a; i++) cin >> p[i];
	for (int i = 0; i < b; i++) cin >> q[i];
	for (int i = 0; i < c; i++) cin >> r[i];
	sort(p.begin(), p.end(), greater<int>());
	sort(q.begin(), q.end(), greater<int>());
	p.resize(x);
	q.resize(y);
	//p.reserve(3 * MAX);
	p.insert(p.end(), q.begin(), q.end());
	p.insert(p.end(), r.begin(), r.end());
	sort(p.begin(), p.end(), greater<int>());
	long long ans = 0;
	for (int i = 0; i < x+y; i++) {
		ans += p[i];
	}
	cout << ans << endl;
	return 0;
}