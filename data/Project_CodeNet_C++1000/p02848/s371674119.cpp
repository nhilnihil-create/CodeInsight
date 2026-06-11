#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_rotn(void) {
	int n;
	string s;
	cin >> n >> s;

	for (int i = 0; i < s.size(); i++) {
		s[i] = s[i] + n;
		if (s[i] - 'A' >= 26) {
			s[i] -= 26;
		}
	}

	cout << s << endl;
}

int main()
{
    b_rotn();

    return 0;
}