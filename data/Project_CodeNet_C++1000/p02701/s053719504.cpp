#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
//		freopen("in1.txt", "r", stdin);
//		freopen("in1.txt", "w", stdout);
	#endif
	set<string> vis;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		vis.insert(s);
	}
	cout << vis.size() << '\n';
}