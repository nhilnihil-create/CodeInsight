#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

char pop(stack<char>& st) {
	char c = st.top();
	st.pop();
	return c;
}

int main() {
	for (;;) {
		string s; getline(cin, s);
		if (s == ".") break;
		stack<char> st;
		bool flag = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') st.push('(');
			if (s[i] == '[') st.push('[');
			if (s[i] == ')')
				if (st.empty() || pop(st) == '[') flag = false;
			if (s[i] == ']')
				if (st.empty() || pop(st) == '(') flag = false;
		}
		if (!st.empty()) flag = false;
		cout << (flag ? "yes" : "no") << endl;
	}
}