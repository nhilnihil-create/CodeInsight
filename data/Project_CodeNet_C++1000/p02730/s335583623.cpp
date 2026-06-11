#include <bits/stdc++.h>
using namespace std;

bool isPal(string s, int n){
	for(int i=0; i < n/2; i++){
		if(s[i]!=s[n-i-1])
			return false;
	}
	return true;
}

int main() {
	string s;
	cin >> s;
	int n = s.length();
	if(n == 1){
		cout << "Yes" << endl; return 0;
	}	
	string s1 = s.substr(0, n/2);
	string s2 = s.substr(n/2+1, n/2);
	if(isPal(s, n) && isPal(s1, n/2) && isPal(s2, n/2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}