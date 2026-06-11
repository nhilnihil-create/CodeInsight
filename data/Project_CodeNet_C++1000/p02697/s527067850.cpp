#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;



int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	if (n % 2 == 1) {
		for (int i = 1; i <= m; i++) {
			cout << i << " " << n - i + 1 << "\n";
		}
	}
	else {
		int diff = n - 1;
		vector<int> used(n);
		for (int i = 1; i <= m; i++) {
			used[n - diff] = 1;
			if (!used[diff]) {
				cout << i << " " << i + diff << "\n";
			}
			else {
				diff--;
				cout << i << " " << i + diff << "\n";
			}
			diff -= 2;
		}
	}
}