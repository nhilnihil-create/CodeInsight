#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1" << endl;
		return 0;
	}
	pair<int, int> a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	int ans = 1000000007;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int x = a[j].first - a[i].first;
			int y = a[j].second - a[i].second;
			int co = n;
			for (int k = 0; k < n; k++) {
				for (int l = k + 1; l < n; l++) {
					if (a[l].first - a[k].first == x && a[l].second - a[k].second == y) {
						co--;
					}
				}
			}
			if (ans > co) {
				ans = co;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
