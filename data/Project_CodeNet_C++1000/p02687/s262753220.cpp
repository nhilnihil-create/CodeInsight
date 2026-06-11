#include <iostream>
#include <string>

using namespace std;

int main() {
	string S, T;
	cin >> S;
	if (S == "ABC") T = "ARC";
	if (S == "ARC") T = "ABC";
	cout << T << endl;

	return 0;
}