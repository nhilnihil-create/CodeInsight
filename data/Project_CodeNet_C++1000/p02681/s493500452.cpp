#include <bits/stdc++.h>
using namespace std;

string s, t;

int main () {
	cin >> s >> t;
	if (t.substr(0,s.length())== s){
		cout << "Yes";	
	} else {
		cout << "No";
	}
}