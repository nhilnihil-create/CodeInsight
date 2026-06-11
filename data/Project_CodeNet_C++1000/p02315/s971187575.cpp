#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

#define int long long
#define MOD7 1000000007
#define MOD9 1000000009

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()

using namespace std;

int nextInt() {int a; cin >> a; return a;}
char nextChar() {char a; cin >> a; return a;}
double nextDouble() {double a; cin >> a; return a;}
string nextString() {string a; cin >> a; return a;}

void inputVector(vector<int> &v, int &n) {rep(i,n){v.push_back(nextInt());}}
void inputVector(vector<double> &v, int &n) {rep(i,n){v.push_back(nextDouble());}}
void inputVector(vector<string> &v, int &n) {rep(i,n){v.push_back(nextString());}}

int dp[110][10010];

signed main() {
	int N, W;
	cin >> N >> W;

	vector<int> v, w;
	rep(i, N) {
		int a, b;
		cin >> a >> b;
		v.push_back(a);
		w.push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 10000; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (j >= w[i - 1]) {
				dp[i][j] = max(dp[i - 1][j - w[i - 1]] + v[i - 1], dp[i][j]);
			}
		}
	}

	cout << dp[N][W] << endl;

    return 0;
}