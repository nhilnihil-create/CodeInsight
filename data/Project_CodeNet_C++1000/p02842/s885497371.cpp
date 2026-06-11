#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 500000; i++) {
		if (i * 1.08 < N + 1 && i * 1.08 >= N) {
			cout << i << endl; return 0;
		}
	}

		cout << ":(" << endl;
	return 0;
}
