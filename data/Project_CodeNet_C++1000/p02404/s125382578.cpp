#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

#define ll long long
#define ull unsigned long long
#define all(a) (a).begin(), (a).end()

int main() {
	int h, w;
	while (cin >> h >> w && h > 0) {
		cout << string(w, '#') << endl;
		for (int i = 0; i < h - 2; ++i)
			cout << '#' << string(w - 2, '.') << '#' << endl;
		cout << string(w, '#') << endl << endl;
	}

	return 0;
}
