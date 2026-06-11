#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <tuple>
#include <functional>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <map>
#include <random>
#include <cstdlib>
#define INT_MAX 2147483647
#define INT_MIN -2147483646
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#define Loop1(i, n) for(int i = 1; i <= (int)n; i++)
#define Loopr(i, n) for(int i = (int)n - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = (int)n; i >= 1; i--)
using namespace std;
typedef long long int ll;

string x, y;
int memo[1005][1005];

int dp(int a, int b) {
	if (memo[a][b] != INT_MIN) return memo[a][b];
	if (a == 0 || b == 0) memo[a][b] = 0;
	else if (x[a - 1] == y[b - 1]) {
		memo[a][b] = dp(a - 1, b - 1) + 1;
	}
	else {
		memo[a][b] = max(dp(a - 1, b), dp(a, b - 1));
	}
	return memo[a][b];
}

int main() {
	int q;
	cin >> q;
	Loop(i, q) {
		cin >> x >> y;
		Loop(j, x.size()+1) {
			Loop(k, y.size()+1) {
				memo[j][k] = INT_MIN;
			}
		}
		cout << dp(x.size(), y.size()) << endl;
	}
	return 0;
}