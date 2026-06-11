#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n;

void dfs(string s, char mx) {
	if (s.size() == n) {
		cout << s << endl;
		return;
	}
	for (char c = 'a'; c <= mx + 1; c++) {
		string ns = s + c;
		dfs(ns, max(mx, c));
	}
}

int main() {
	cin >> n;
	dfs("", 'a'-1);
}