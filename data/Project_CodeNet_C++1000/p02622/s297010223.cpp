#include <iostream>
#include <string>
using namespace std;
int main()
{
	int x = 0;
	string S, T;
	cin >> S >> T;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] != T[i])
			x += 1;
	}
	cout << x << "\n";
}