#include <iostream>
using namespace std;

int main() {
	string S;
	cin >> S;
	int ans = 0;
	char now = ' ';
	for (int i = 0; i < S.length(); i++) {
		if (S[i] != now) now = S[i];
		else {
			i++;
			now = ' ';
			if (i == S.length()) ans--;
		}
		ans++;
	}
	cout << ans << endl;
}
