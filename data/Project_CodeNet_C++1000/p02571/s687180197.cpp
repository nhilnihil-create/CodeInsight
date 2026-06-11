#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	int ans = t.size();

	for (int start = 0; start <= s.size() - t.size(); start++) {
		int diff = 0;
		for (int i = 0; i < t.size(); i++) {
			if (t[i] != s[start + i]) {
				diff++;
			}
		}
		ans = min(ans, diff);
	}
	cout << ans << endl;
	return 0;
}