#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	uint64_t S,W;
	cin >> S >> W;

	cout << (S>W ? "safe\n": "unsafe\n" );
	return 0;
}

