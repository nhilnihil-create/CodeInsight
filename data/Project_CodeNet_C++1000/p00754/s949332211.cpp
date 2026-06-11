#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<numeric>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<utility>
#include<sstream>
#include<complex>
#include<fstream>
#include<bitset>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define rep(i,N) for(int i=0;i<(N);i++)

int main() {
	string s;
	while (getline(cin, s)) {
		if (s.size() == 1 && s[0] == '.') {
			break;
		}
		int a, b;
		a = b = 0;
		bool h = true;
		stack<int> stk;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				a++;
				stk.push(1);
			}
			else if (s[i] == ')') {
				a--;
				if (!stk.empty()) {
					int r = stk.top();
					stk.pop();
					if (r == 2) {
						h = false;
					}
				}
			}
			else if (s[i] == '[') {
				b++;
				stk.push(2);
			}
			else if (s[i] == ']') {
				b--;
				if (!stk.empty()) {
					int r = stk.top();
					stk.pop();
					if (r == 1) {
						h = false;
					}
				}
			}
			if (a < 0 || b < 0) {
				h = false;
			}
		}
		if (a != 0 || b != 0) {
			h = false;
		}
		if (h) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}