#include <bits/stdc++.h>
using namespace std;

int main() {
	//input
	int N, X, T;
	cin >> N >> X >> T;

	//calculation
	int output = (N - 1) / X + 1;
	output = output * T;

	//output
	cout << output << endl;


	return 0;
}
