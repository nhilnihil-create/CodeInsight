#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 1000000007

int main() {
	int n;
	cin >> n;
	if (n == 3) {
		cout << "Yes" << endl;
		for (int i = 1; i < 2 * n; i++) {
			cout << i << " " << i + 1 << endl;
		}
		return 0;
	}
	int tmp = 0;
	while ((1 << tmp) < n) tmp++;
	if ((1 << tmp) == n) {
		cout << "No" << endl;
		return 0;
	}
	tmp--;
	cout << "Yes" << endl;
	tmp = (1 << tmp) - 1;
	// 頂点番号1~tmpを並べてつなげる
	for (int i = 1; i < tmp; i++) {
		cout << i << " " << i + 1 << endl;
	}
	// 頂点n + 1とtmpをつなげる
	cout << tmp << " " << n + 1 << endl;
	// 頂点n + 1 ~ n + tmpを並べてつなげる
	for (int i = 2; i <= tmp; i++) {
		cout << n + i - 1 << " " << n + i << endl;
	}
	if (n == tmp) {
		return 0;
	}
	// 頂点tmp + 1、tmp + 2を頂点1につなげる
	cout << 1 << " " << tmp + 1 << endl;
	cout << 1 << " " << tmp + 2 << endl;
	// 頂点tmp + 1 + nをtmp + 2に、tmp + 2 + nをtmp + 1につなげる
	cout << tmp + 1 << " " << tmp + 2 + n << endl;
	cout << tmp + 2 << " " << tmp + 1 + n << endl;
	int tmpp = 0;
	for (int i = 2; i <= tmp; i += 2) {
		tmpp ^= (i ^ (i - 1));
		// cout << tmpp << endl;
		if (((tmp + 1) ^ tmpp) <= n) {
			cout << tmp + 1 << " " << ((tmp + 1) ^ tmpp) << endl;
			cout << i << " " << ((tmp + 1) ^ tmpp) + n << endl;
		}
		if (((tmp + 2) ^ tmpp) <= n) {
			cout << tmp + 2 << " " << ((tmp + 2) ^ tmpp) << endl;
			cout << i << " " << ((tmp + 2) ^ tmpp) + n << endl;
		}
	}
}