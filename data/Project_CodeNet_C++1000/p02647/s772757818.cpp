#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const int MAX = 1e5+5;



int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < k; i++) {
		vector<int> b(n);
		for (int j = 0; j < n; j++) {
			int l = max(0, j - a[j]);
			int r = min(n - 1, j + a[j]);
			b[l]++;
			if (r + 1 < n) {
				b[r + 1]--;
			}
		}
		for (int j = 1; j < n; j++) {
			b[j] += b[j - 1];
		}

		bool isEnd = true;
		for (int j = 0; j < n; j++) {
			if (a[j] != n) {
				isEnd = false;
				break;
			}
		}

		if (isEnd) {
			for (int j = 0; j < n; j++) {
				cout << n << " ";
			}
			cout << endl;
			return 0;
		}
		a = b;
	}

	for (int ai : a) {
		cout << ai << " ";
	}

	cout << endl;
}