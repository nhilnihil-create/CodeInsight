#include <iostream>
using namespace std;
int main() {
	// your code goes here
	char c; 
    cin >> c;
	if (islower(c)) {
	    cout << 'a';
	} else {
	    cout << 'A';
	}
	return 0;
}