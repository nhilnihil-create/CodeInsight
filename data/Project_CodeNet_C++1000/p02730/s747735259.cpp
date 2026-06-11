#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s){
	string tmp = s;
	reverse(s.begin(),s.end());
	return s == tmp;
}


int main(){
	string s;
	cin >> s;
	int len = s.size();
	bool ok = is_palindrome(s) & is_palindrome(s.substr(0,len / 2)) & is_palindrome(s.substr(len / 2 + 1,len));
	if(ok){
		cout << "Yes";
	} else{
		cout << "No";
	}
	return 0;
}
