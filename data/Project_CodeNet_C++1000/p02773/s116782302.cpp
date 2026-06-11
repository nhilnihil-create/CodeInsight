#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
//setprecision(15)


map<string, int> memo;

int main() {
	int n; cin >> n;
	rep(i, n) {
		string s; cin >> s;
		memo[s] += 1;
	}
	int maxv = 0;
	for (auto it = memo.begin(); it != memo.end(); it++) {
		maxv = max(maxv, it->second);
	}
	for (auto it = memo.begin(); it != memo.end(); it++) {
		if (it->second == maxv) {
			cout << it->first << endl;
		}
	}
}