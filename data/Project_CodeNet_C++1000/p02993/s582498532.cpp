#include <iostream>
#include <string>
using namespace std;

int main()
{
	int ans = 0;
	string A;
	cin >> A;

	for (int i = 0; i < 3; i++) {
		if (A.at(i) == A.at(i + 1)) {
			ans = 1;
		}
	}
	if (ans == 1) {
		cout << "Bad";
	}
	else
		cout << "Good";
}
