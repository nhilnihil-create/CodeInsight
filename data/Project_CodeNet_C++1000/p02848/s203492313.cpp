#include <bits/stdc++.h>
#define fast_io ios :: sync_with_stdio(false);
using namespace std;

int main() {
	cout << fixed << setprecision(3);
	fast_io;
	int n; cin >> n;
	string s; cin >> s;
	string r;
	char l;
	if(n != 0) {
		for (int i = 0; i < s.size(); i++) {
			if(int(s[i]) + n > int('Z')) {
				l = char(int(s[i]) + n - 26);		
			} else {
				l = int(s[i] + n);
			}
			if(r == "") {
				r = l; 
			} else {
				r += l;
			}
		}	
	} else {
		r = s;	
	}
	cout << r;
	return 0;	
}