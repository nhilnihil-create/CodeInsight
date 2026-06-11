#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int N = 2007, inf = 0x3f3f3f3f, M = 1e9 + 7;


int memo[N];

int solve(int s) {
	if(s == 0) return 1;
	if(s < 3) return 0;

	int & st = memo[s];

	if(st == -1) {
		st = 0;
		for(int i = 3; i <= s; ++i) st = (st + solve(s - i))%M;
	}
	return st;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	memset(memo, -1, sizeof memo);
	int s; cin >> s;
	cout << solve(s) << endl;
}