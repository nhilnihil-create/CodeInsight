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



int main() {
	int n;
	cin >> n;


	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	vector<int> c(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		sum += b;


	}

	for (int i = 0; i < n - 1; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] == a[i] + 1) {
			sum += c[a[i]];
		}
	}
	cout << sum << endl;

}
