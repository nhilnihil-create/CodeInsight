#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <tuple>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
//cin.sync_with_stdio(false);
//streambuf
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<bool> pf(1000000, true);
vector<int> p;
int main() {
	pf[0] = pf[1] = 0;
	for (int i = 2; i < 1000; i++) {
		if (!pf[i])continue;
		for (int j = i * 2; j < 1000000; j += i) {
			pf[j] = 0;
		}
	}
	//for (int i = 0; i < 1000000; i++) {
	//	if (pf[i])p.push_back(i);
	//}
	int a, b, n;
	while (cin >> a >> b >> n, a) {
		int cnt = 0;
		int i = a;
		for (;; i += b) {
			if (pf[i])cnt++;
			if (cnt == n)break;
		}
		cout << i << endl;
	}
	return 0;
}