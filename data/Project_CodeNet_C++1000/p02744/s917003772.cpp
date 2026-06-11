#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = 1001002003004005006ll;
const int inf = 1001001001;
const int mod = 1000000007;

int n;

void dfs(string s, char c) {
	if (s.size() == n) {
		cout << s << endl;
	}
	else {
		for (char i = 'a'; i <= c; ++i) {
			if (i == c) dfs(s + i, c + 1);
			else dfs(s + i, c);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dfs("", 'a');
	return 0;
}