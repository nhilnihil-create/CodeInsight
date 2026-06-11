#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a, L;
	while ( cin >> a >> L, a || L ) {
		map<int, int> m;
		m[a] = 0;
		int ans = -1;
		int t = 0;
		while (++t) {
			vector<int> v(L);
			for (int i = 0, k = a; i < L; ++i, k /= 10) {
				v[i] = k % 10;
			}
			sort(v.begin(), v.end());

			int B = 0;
			for (int i = v.size()-1; i >= 0; --i) {
				B = B * 10 + v[i];
			}
			int b = 0;
			for (int i = 0; i < v.size(); ++i) {
				b = b * 10 + v[i];
			}
			a = B - b;

			if (m.find(a) != m.end()) {
				cout << m[a] << " " << a << " " << (t-m[a]) << endl;
				break;
			}
			m[a] = t;
		}
	}
}