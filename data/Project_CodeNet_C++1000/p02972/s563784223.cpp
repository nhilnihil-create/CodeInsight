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
int a[200020];
int co[200020] = { 0 };
vector<int> ans;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i > 0; i--) {
		if (a[i] % 2 != co[i] % 2) {
			ans.push_back(i);
			for (int j = 1; j * j <= i; j++) {
				if ((i) % j == 0) {
					co[j]++;
					if (j != i / j) {
						co[i / j]++;
					}
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}
