#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

string S;

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '?') S[i] = 'D';
	}
	cout << S << endl;
	return 0;
}