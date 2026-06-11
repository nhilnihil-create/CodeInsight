#include <iostream>
#include <vector>
#include <string>

using namespace  std;

int main() {
	long int N;
	cin >> N;

	vector<int> data(N,0);
	for (int i = 0; i < N; i++) {
		cin >> data.at(i);
	}
	int counter = 1;
	for (int i = 0; i < N; i++) {
		if (counter == data.at(i))counter++;
	}
	if (counter == 1) {
		cout << -1 << endl;
	}
	else {
		cout << N + 1 - counter << endl;
	}
	return 0;
}