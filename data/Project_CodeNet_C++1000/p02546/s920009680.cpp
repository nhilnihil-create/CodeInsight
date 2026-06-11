#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <cctype>
#include <random>

using namespace std;
typedef long long  ll;
const ll INF = 1000000007;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)


int main() {
	string s;
	cin >> s;
	if (s[s.length() - 1] == 's') {
		s += "es";
	}
	else {
		s += "s";
	}
	cout << s << endl;
	return 0;
}