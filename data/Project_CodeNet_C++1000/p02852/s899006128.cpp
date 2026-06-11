#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> ans;
	for(int i = n; i >=0; ) {
		if(i <= m) {
			ans.push_back(i);
			break;
		}
		int now = -1;
		for(int j = m; j >=1; j--) {
			if(s[i-j] != '1') {
				ans.push_back(j);
				now = j;
				i -= j;
				break;
			}
		}
		if(now == -1) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	reverse(all(ans));
	rep(i, ans.size()) printf("%d%c", ans[i], (i==ans.size()-1) ? '\n' : ' ');
	return 0;
}