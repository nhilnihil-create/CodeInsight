#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

string s;
int n, dp[6000][6000], dq[6000][6000];

int rec(int l1, int l2) {
	if (l1 >= n || l2 >= n) return 0;
	if (dq[l1][l2] == 0) {
		if (s[l1] == s[l2]) dp[l1][l2] = min(abs(l1 - l2), rec(l1 + 1, l2 + 1) + 1);
		dq[l1][l2] = 1;
	}
	return dp[l1][l2];
}

int main() {
	cin >> n >> s;
	int r = 0;
	rep(i, n)rep(j, n)r = max(r, rec(i, j));
	cout << r << endl;
}