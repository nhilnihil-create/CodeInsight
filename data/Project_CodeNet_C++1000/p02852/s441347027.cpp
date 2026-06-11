#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> a;
	rep(i, n + 1) {
		if (s[i] == '0') a.push_back(i);
	}
	vector<int> ans;
	int now = n;
	while (now != 0) {
		auto ite = upper_bound(a.begin(), a.end(), now - m-1);
		if (*ite == now) {
			cout << -1 << endl;
			return 0;
		}
		ans.push_back(now-*ite);
		now = *ite;
	}
	reverse(ans.begin(), ans.end());
	rep(i, ans.size()) cout << ans[i] << " ";
	cout << endl;
}