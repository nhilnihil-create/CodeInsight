#include <iostream>
#include <string>

using namespace std;
int main() {
	// your code goes here
	int max = 0;
	int all = 0;
	string s;
	cin >> s;
	for (int i = 0; i < 3; i++) { 
	    if (s[i] == 'R') {
	        max += 1;
	    } else {
	        max = 0;
	    }
	    if (max > all) {
	        all = max;
	    }
    }
    cout << all;
	return 0;
}