#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

int in() {
	int res = 0;
	for(int i = 0; i < 4; ++i) {
		int in;
		cin >> in;
		res += in;
	}

	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cout << max(in(), in()) << endl;

	return EXIT_SUCCESS;
}