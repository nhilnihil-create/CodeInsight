#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	string S, T, A;
	cin >> S >> T;
	for (int i = 0; i < N; i++) {
		A.push_back(S[i]);
		A.push_back(T[i]);
	}
	cout << A << endl;
	return 0;
}