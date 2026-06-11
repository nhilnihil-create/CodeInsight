#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
using namespace std;

int main() {
	string s;
	bool f = 1;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) {
			if (!(s[i] == 'R' || s[i] == 'U' || s[i] == 'D')) {
				f = 0;
			}
		}
		else {
			if (!(s[i] == 'L' || s[i] == 'U' || s[i] == 'D')) {
				f = 0;
			}
		}
	}
	if (f == 1)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}