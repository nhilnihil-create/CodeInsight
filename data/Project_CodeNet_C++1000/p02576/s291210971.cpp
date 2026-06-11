#include <iostream>

using namespace std;

int main() {
	int N, X, T;
   double num;
	cin >> N >> X >> T;
	num = N / X;
	if (N % X) num++;
	num *= T;
	cout << int(num) << endl;
	return 0;
}