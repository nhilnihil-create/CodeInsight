#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	string S, T, U;
	int A, B;
	cin >> S >> T >> A >> B >> U;
	if (U == S) A--;
	if (U == T) B--;
	cout << A << " " << B << endl;
	return 0;
}