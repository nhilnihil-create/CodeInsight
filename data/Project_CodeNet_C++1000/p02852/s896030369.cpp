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
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;

//typedef modint998244353 mint;

const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const ll MAX = 1e9 + 5;

int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	//cout << s << endl;
	vector<int> ans;
	int p = 0;
	while (p < n) {
		int a = 0;
		for (int i = 1; i <= m; i++) {
			if (p + i > n) {
				break;
			}
			if (s[p + i] == '0') {
				a = i;
			}
		}
		if (a == 0) {
			cout << -1 << endl;
			return 0;
		}
		ans.emplace_back(a);
		p += a;

		
	}

	reverse(ans.begin(),ans.end());

	for (int ai: ans) {
		cout << ai << " ";
	}
}