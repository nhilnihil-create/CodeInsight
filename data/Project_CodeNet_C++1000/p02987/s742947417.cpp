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
	string s;
	cin >> s;

	map<char, int> m;
	for (int i = 0; i < 4; i++) {
		m[s[i]]++;


	}

	bool isConsist = true;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second != 2) {
			isConsist = false;
			break;
		}
	}

	if (isConsist) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}
