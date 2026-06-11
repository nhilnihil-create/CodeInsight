#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int H1, M1, H2, M2, K;

int main() {
	cin >> H1 >> M1 >> H2 >> M2 >> K;
	int S1 = H1 * 60 + M1;
	int S2 = H2 * 60 + M2;
	cout << S2 - S1 - K << endl;
	return 0;
}