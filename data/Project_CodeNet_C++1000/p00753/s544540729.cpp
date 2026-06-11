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

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int nextInt() {int a; cin >> a; return a;}
char nextChar() {char a; cin >> a; return a;}
double nextDouble() {double a; cin >> a; return a;}
string nextString() {string a; cin >> a; return a;}

void inputVector(vector<int> &v, int &n) {rep(i,n){v.push_back(nextInt());}}
void inputVector(vector<double> &v, int &n) {rep(i,n){v.push_back(nextDouble());}}
void inputVector(vector<string> &v, int &n) {rep(i,n){v.push_back(nextString());}}

bool prime[300000];
int cnt[300000];

signed main() {
	memset(prime, true, sizeof(prime));
	prime[1] = false;

	int c = 0;
	for (int i = 2; i < 300000; i++) {
		if (!prime[i]) {
			cnt[i] = c;
			continue;
		}
		for (int j = 2 * i; j < 300000; j += i) {
			prime[j] = false;
		}
		c++;
		cnt[i] = c;
	}

	while (true) {
		int n;
		cin >> n;

		if (n == 0) break;

		cout << (cnt[2 * n] - cnt[n]) << endl;
	}

    return 0;
}