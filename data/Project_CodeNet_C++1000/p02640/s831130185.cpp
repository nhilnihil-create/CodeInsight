#include <iostream>
using namespace std;

int main() {
	int X, Y;
	cin >> X >> Y;
	bool answer;
	if (Y % 2) {
		answer = false;
	}
	else {
		if ((Y >= 2 * X) && (Y <= 4 * X)) answer = true;
		else answer = false;
	}
	if (answer)printf("Yes");
	else printf("No");
}