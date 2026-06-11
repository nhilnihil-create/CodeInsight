#include<iostream>
using namespace std;

int main() {

	int N = 0;
	int X = 0;
	int T = 0;

	do {

		cin >> N >> X >> T;

	} while (N < 1 || N > 10000 || X < 1 || X > 10000 || T < 1 || T > 10000);

	int frequency = N / X;
	int surplus = N % X;


	if (surplus != 0) {
		frequency++;
	}

	cout << T* frequency;

}