

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;



int main() {
	int n, m;
	cin >> n >> m;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	set<int> s;

	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		a--;
		b--;
		if (h[a] >= h[b]) {
			s.insert(b);
		}
		if (h[b] >= h[a]) {
			s.insert(a);
		}


	}

	cout << n - s.size() << endl;


}