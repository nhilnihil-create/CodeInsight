#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	string s;
	cin >> s;

	int N = 0;
	N = s.size();

	bool first = true, second = true, therd = true;

	for (int i = 0; i < N/2; ++i) {
		if (s.at(i) != s.at(N - i - 1)) {
			first = false;
		}
	}


	string s2;
	s2 = s.substr(0, (N - 1) / 2);

	int N2 = s2.size();

	for (int i = 0; i < N2 / 2; ++i) {
		if (s2.at(i) != s2.at(N2 - 1 - i)) {
			second = false;
		}
	}

	int N3 = (N + 3) / 2;
	string s3 = s.substr(N3 - 1);
	N3 = s3.size();

	for (int i = 0; i < N3 / 2; ++i) {
		if (s3.at(i) != s3.at(N3 - 1 - i)) {
			therd = false;
		}
	}

	if (first && second && therd) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}