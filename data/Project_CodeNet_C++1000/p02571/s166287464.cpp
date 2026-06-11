#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	string a, b; cin >> a >> b;
	int length = b.length();
	int max = 0;
	for (int i = 0; i < a.length() - length + 1; i++) {
	    int cur_max = 0;
	    string str = "";
	    for (int x = 0; x < length; x++) {
	        if (b[x] == a[i + x]) {
	            cur_max++;
	        }
	    }
	    
	    if (cur_max > max) {
	        max = cur_max;
	    }
	    
	}
	cout << length - max;
	
	return 0;
}