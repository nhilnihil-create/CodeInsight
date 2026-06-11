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
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}

	int m = BIG_NUM;
	for (int i = 0; i < n - 1; i++) {
		int s1 = 0;
		for (int j = 0; j <= i; j++) {
			s1 += w[j];
		}
		int s2 = 0;
		for (int j = i + 1; j < n; j++) {
			s2 += w[j];
		}
		m = min(m, abs(s1 - s2));

	}
	cout << m << endl;
}
