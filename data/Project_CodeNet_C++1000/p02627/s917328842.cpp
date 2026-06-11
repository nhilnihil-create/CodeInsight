#include <iostream>
using namespace std;

int main() {
	char c; cin >> c;
	int index = (int)c;
	if (index >= 65 && index <= 90) {
	    cout << 'A';
	} else {
	    cout << 'a';
	}
}