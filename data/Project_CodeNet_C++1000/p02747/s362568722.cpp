#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string S;
	cin >> S;

	int len = S.length();
	string ans = "No";
	if (len % 2 == 0) {
		int k = len / 2;
		string t = "";
		for (int i = 0; i < k; ++i)
			t += "hi";
		if (S == t)
			ans = "Yes";
	}
	cout << ans << '\n';

	return 0;
}
