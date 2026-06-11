#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int n;

void dfs(string s) {

	if (s.size() == n)cout << s << endl;
	else {
		int mx = -1;
		rep(i, s.size())mx = max(mx, s[i] - 'a');

		rep(i, mx + 2) {
			char c = 'a' + i;
			string ss = s;
			ss += c;
			dfs(ss);
		}
	}
}


int main() {

	cin >> n;
	dfs("");

}