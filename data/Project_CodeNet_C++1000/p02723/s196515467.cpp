#include <bits/stdc++.h>
using namespace std;

string s;
char a, b, c, d;

int main () {
	cin >> s;
	a = s[2];
	b = s[3];
	c = s[4];
	d = s[5];
	if (a==b && c==d){
		cout << "Yes";
	} else {
		cout << "No";
	}
}