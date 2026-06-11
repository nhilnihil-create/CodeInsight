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
	string s;
	cin >> s;

	if (n % 2 != 0) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 0; i < n/2; i++) {
		if (s[i] != s[i + n / 2]) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
}
