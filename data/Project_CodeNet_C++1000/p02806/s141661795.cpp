#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<pair<string,int>>len(n);
	for (int i = 0; i < n; i++)cin >> len.at(i).first >> len.at(i).second;
	string s;
	cin >> s;
	int ans = 0;
	bool x = false;
	for (int i = 0; i < n; i++) {
		if (x == false) {
			if (len.at(i).first == s) x = true;
		}
		else ans += len.at(i).second;
	}
	cout << ans << endl;
}