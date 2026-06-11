#include<iostream>
using namespace std;

int main() {
	int K, X;
	cin >> K >> X;

	int firstBlack = X - K;
	for (int i = 0; i < 2 * K - 1; i++) {
		firstBlack++;
		if (i < 2 * K - 2) {
			cout << firstBlack << " ";
		}
		else {
			cout << firstBlack << endl;
		}
	}


}
