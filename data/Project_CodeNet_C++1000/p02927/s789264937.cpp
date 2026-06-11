#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	int M, D;
	cin >> M >> D;
	int ans = 0;
	for (int m = 1; m <= M; m++) {
		for (int d1 = 2; d1 <= 9; d1++) {
			for (int d10 = 2; d10 <= 9; d10++) {
				int day = d1 + d10 * 10;
				if (day > D)break;
				if (d1 * d10 == m)ans++;
			}
		}
	}
	cout << ans << endl;
}