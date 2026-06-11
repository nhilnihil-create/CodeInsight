#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_string_palindorme(void) {
	string s;
	cin >> s;
	int n = s.size();
	int n_1 = (n - 1) / 2;
	int n_3 = (n + 3) / 2 - 1;

	string s_upper = s.substr(0, n_1);
	string s_lower = s.substr(n_3, n-n_3);
	//cout << s_upper << " " << s_lower << endl;

	string judge = "Yes";
	for (int i = 0; i < n; i++) {
		if (s[i] != s[n - i - 1]) {
			judge = "No";
			break;
		}
	}

	for (int i = 0; i < s_upper.size(); i++) {
		if (s_upper[i] != s_upper[s_upper.size() - i - 1]) {
			judge = "No";
			break;
		}
	}

	for (int i = 0; i < s_lower.size(); i++) {
		if (s_lower[i] != s_lower[s_lower.size() - i - 1]) {
			judge = "No";
			break;
		}
	}

	cout << judge << endl;
}

int main()
{
    b_string_palindorme();

    return 0;
}
