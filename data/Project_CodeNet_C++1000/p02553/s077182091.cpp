#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<long long> left(2, 0), right(2, 0);
	for (auto &inum : left) {
		cin >> inum;
	}
	for (auto& inum : right) {
		cin >> inum;
	}
	long long max = -1000000000000000000;
	for(int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++) {
			long long expr = left[i] * right[j];
			if (expr > max) max = expr;
		}
	}

	cout << max;
}