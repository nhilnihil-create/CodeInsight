#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int MSB = 0;//0-idx
	while (N >= (1 << MSB))MSB++;
	MSB--;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = 0; k <= MSB; k++) {
				if ((i & (1 << k)) != (j & (1 << k))) {
					cout << k + 1 << " ";
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}