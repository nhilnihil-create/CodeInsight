#include<bits/stdc++.h>
using namespace std;

//#define int long long

signed main() {
	string s;
	cin >> s;
	int k;
	cin >> k;

	char c = s[0];
	int ccnt = 0;
	for (int i = 0; i < s.size(); ++i) if (s[i] == c) ++ccnt;
	if (ccnt == s.size()) {
		long long a = (long long)k * ccnt / 2;
		cout << a << endl;
		return 0;
	}

	s.push_back('X');
	long long ans = 0;
	bool first = true;
	int cnt = 1, cntf = 0, cntb = 0;
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] == s[i + 1]) cnt++;
		else {
			if (first) {
				cntf = cnt;
				cnt = 1;
				first = false;
			}
			else if (s[i + 1] == 'X') {
				cntb = cnt;
			}
			else {
				ans += (long long) k * (cnt / 2);
				cnt = 1;
			}
		}
		//cout << i << "  " << ans << endl; 
	}

	

	//cout << cntf << " " << cntb << endl;
	//cout << ans << endl;



	if (s[0] != s[s.size() - 2]) ans += (long long)k * (cntf / 2 + cntb / 2);
	else ans += (long long)(k - 1) * ((cntf + cntb) / 2) + cntf / 2 + cntb / 2;

	cout << ans << endl;
	return 0;
}
