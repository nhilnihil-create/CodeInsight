#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string S;
	cin >> S;

	int n = S.length();
	if (S[n - 1] == 's')
		S = S + "es";
	else
		S += 's';

	cout << S << '\n';
	return 0;
}
