#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int>x;
	x.push_back(0);
	int N = 0;
	int num = 0;
	int counter = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		x.push_back(num);
	}

	for (int i = 1; i < x.size(); i++) {
		if (x[i] % 2 != 0 && i % 2 != 0) {
			counter++;
		}
	}
	cout << counter;
	return 0;
}