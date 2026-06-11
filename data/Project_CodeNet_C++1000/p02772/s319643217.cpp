#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace  std;


int main() {
	int N;
	cin >> N;
	vector<int> data(N);
	for (int i = 0; i < N; i++) {
		cin >> data.at(i);
	}
	bool accept = true;
	for (int i = 0; i < N; i++) {
		if (data.at(i) % 2 == 0) {
			if (data.at(i) % 3 == 0) {
				continue;
			}
			else if (data.at(i) % 5 == 0) {
				continue;
			}
			else {
				accept = false;
			}
		}
	}
	if (accept == true) {
		cout << "APPROVED" << endl;
	}
	else {

		cout << "DENIED" << endl;
	}
	return 0;
}