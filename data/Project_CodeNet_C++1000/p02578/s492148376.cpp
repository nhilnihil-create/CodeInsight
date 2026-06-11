#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	long long N;
	cin >> N;
	long long max_height = 0;
	long long sum_height = 0;
	for (int i = 0; i < N; ++i) {
		int A;
		cin >> A;
		if (A < max_height) {
			sum_height += max_height - A;
		}
		else {
			max_height = A;
		}
	}
	cout << sum_height << endl;
}