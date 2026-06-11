#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void b_minor_change(void) {
	string s, t;
	cin >> s >> t;

	int diff = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i])diff++;
	}

	cout << diff << endl;;
}

int main()
{
    b_minor_change();
    return 0;
}
