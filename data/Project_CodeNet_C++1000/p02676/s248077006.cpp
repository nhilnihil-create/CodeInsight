#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_triple_dots(void) {
	int k;
	string s;
	cin >> k >> s;

	if (s.size() <= k) {
		cout << s << endl;
		return;
	}

	cout << s.substr(0, k) << "..." << endl;
}

int main()
{
    b_triple_dots();

    return 0;
}