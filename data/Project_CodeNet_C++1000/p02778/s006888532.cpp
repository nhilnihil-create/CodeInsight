#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_i_miss_you(void) {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cout << "x";
	}
	cout << endl;
}

int main()
{
    b_i_miss_you();

    return 0;
}