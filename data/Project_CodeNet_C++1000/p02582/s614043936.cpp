#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int ans = 0, buf = 0;
	for (int i = 0; i < 3; i++) {
		if (str[i] == 'R') {
			buf++;
			ans = max(ans, buf);
		}
		else {
			ans = max(ans, buf);
			buf = 0;
		}
	}
	cout << ans << endl;

	return 0;
}