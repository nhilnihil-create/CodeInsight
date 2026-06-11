#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_tap_dance(void) {
	string s;
	cin >> s;

	string ans = "Yes";

	for (int i = 0; i < s.size(); i++) {
		if ((i & 0x1) == 0x1) {
			if (s[i] == 'R') ans = "No";
		}
		else {
			if (s[i] == 'L') ans = "No";
		}
	}

	cout << ans << endl;
}

int main()
{
    b_tap_dance();

    return 0;
}