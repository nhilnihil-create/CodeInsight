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
		string a, b;
		for (int i = 0; i < w; ++i) {
			a += (i % 2 == 0) ? '#' : '.';
			b += (i % 2 == 1) ? '#' : '.';
		}
		for (int i = 0; i < h; ++i)
			if (i % 2 == 0)
				cout << a << endl;
			else
				cout << b << endl;
		cout << endl;
	}

	return 0;
}
