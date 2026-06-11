#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <vector>;
#include <numeric>
using namespace std;

int main() {
		
	string s;
	cin >> s;

	int k=0;
	for (int i = 0;i < s.length();i++) {
		k += s[i] - '0';
		k %= 9;
	}

	if (k == 0) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	return 0;
}