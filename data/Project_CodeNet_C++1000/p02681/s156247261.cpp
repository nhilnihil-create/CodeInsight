#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define PI 3.14159265358
typedef long long ll; 
typedef long double ld; 

int main() {
	int i, se, count = 0;
	string s, t;
	cin >> s >> t;
	se = s.length();
	for(i = 0; i < se; i++) {
		if(s[i] == t[i]) {
			count++;
		}
	}
	if(count == se && t.length() > s.length()) {
		cout << "Yes" << endl;
	} else cout << "No" << "\n"; 
	
	return 0;
}
