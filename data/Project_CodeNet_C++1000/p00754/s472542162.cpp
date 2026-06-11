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
int t[17][17];
int dp[64 * 1024];
int main() {
	string buf;
	while (getline(cin, buf), buf != ".") {
		vector<char> s;
		bool f = true;
		for (auto a : buf) {
			switch (a) {
			case '(':
			case '[':
				s.push_back(a);
				break;
			case ')':
				if (s.empty() || s.back() != '(') {
					f = false;
					break;
				}
				s.pop_back();
				break;
			case ']':
				if (s.empty() || s.back() != '[') {
					f = false;
					break;
				}
				s.pop_back();
				break;
			}
		}
		if (!s.empty())f = false;
		cout << (f ? "yes" : "no") << endl;
	}
	return 0;
}