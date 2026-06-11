#include <iostream>
#include <string>
using namespace std;
int main() {

	string S, T;
	cin >> S >> T;
	int A, B;
	cin >> A >> B;
	string U;
	cin >> U;
	if (S == U)
		A -= 1;
	else if (T == U)
		B -= 1;
	cout << A << ' ' << B << "\n";
}