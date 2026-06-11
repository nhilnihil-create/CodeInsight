#include <iostream>
using namespace std;

int main() {
	char input;
	cin >> input;
	
	if (islower(input)) {
		cout << "a";
	} else {
		cout << "A";
	}
}
