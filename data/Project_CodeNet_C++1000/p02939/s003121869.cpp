#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int ans = 1;
	char c = s[0];
	for (int i = 1; i < s.length(); i++) {
		if (c == s[i]) {
			if (s.length() - i >= 3) {
				i += 2;
				ans += 2;
			}
			else if (s.length() - i == 2) {
				ans++;
				break;
			}
			else {
				break;
			}
		}
		else {
			ans++;
		}
		c = s[i];
	}
	cout << ans << endl;

	return 0;
}