#include <iostream>
#include <set>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int c = n - 1 - i;
		vector<int> d(c,0);
		int level = 1;
		while (true) {
			int phase = 0;
			for (int i = 0; i < c; ++i) {
				if (d[i] == 0) {
					if (phase == 0) {
						d[i] = level;
						phase = 1;
					}
					else {
						phase = 0;
					}
				}
			}
			bool flag = true;
			for (int i = 0; i < c; ++i) {
				flag = flag & (d[i] != 0);
			}
			if (flag) break;
			else level += 1;
		}
		for (int j = 0; j < n - 1 - i; ++j) {
			cout << d[j];
			if (j + 1 == n - 1 - i) cout << endl;
			else cout << " ";
		}
	}
}