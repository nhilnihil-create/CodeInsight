#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	long long A, B, K;
	cin >> A >> B >> K;
	if (A > K) A -= K;
	else if (A == K) A = 0;
	else {
		if (B < K - A) B = 0;
		else B -= K - A;
		A = 0;
	}
	cout << A << " " << B << endl;
	return 0;
}