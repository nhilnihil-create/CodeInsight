#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
	string s; cin >> s;
	for(int i=1;i<=s.size();i++) {
		if(i%2==0) {
			if(s[i-1]!='L'&&s[i-1]!='U'&&s[i-1]!='D') {
				cout << "No" << endl;
				return 0;
			}
		}
		else {
			if(s[i-1]!='R'&&s[i-1]!='U'&&s[i-1]!='D') {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}