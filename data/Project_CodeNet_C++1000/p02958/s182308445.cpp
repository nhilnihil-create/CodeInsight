#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> p(N);
	for (int i = 0; i < N; i++) cin >> p[i];
	bool ok = true;
	bool once = false;
	for (int i = 0; i < N; i++) {
		if (i + 1 != p[i]) {
			if (once) ok = false;
			else {
				swap(p[i], p[p[i] - 1]);
				once = true;
			}
		}
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}