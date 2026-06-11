#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_countABC(void) {
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0;
	string target = "ABC";
	for (int i = 0; i < n - 2; i++) {
		string sub = s.substr(i, 3);
		if (sub == target) cnt++;
	}

	cout << cnt << endl;
}

int main()
{
    b_countABC();

    return 0;
}
