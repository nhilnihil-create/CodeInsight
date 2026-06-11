#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_echo(void) {
	int n;
	string s;
	cin >> n >> s;

	if (n % 2 == 1) {
		cout << "No" << endl;
		return;
	}

	string s_upper = s.substr(0, n / 2);
	string s_lower = s.substr(n / 2, n / 2);

	//cout << s_upper << " " << s_lower << endl;

	if (s_upper == s_lower) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

int main()
{
    b_echo();

    return 0;
}