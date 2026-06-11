#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define INIT -1

int n;
string s = "";

void solve(int idx, char c) {
	if (idx == n) {
		cout << s << endl;
		return;
	} else {
		for (char nc = 'a'; nc <= c; nc++) {
			s[idx] = nc;
			solve(idx + 1, c);
		}
		s[idx] = c + 1;
		solve(idx + 1, c + 1);
	}
}

int main() {
	cin >> n;
	s = string(n, 'a');
	solve(1, 'a');
}