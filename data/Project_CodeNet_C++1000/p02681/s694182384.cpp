#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	string t;
	cin >> t;
	int flag = 1;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != t[i]){
			flag = 0;
			break;
		}
	}
	if(flag == 0){
		cout << "No";
	} else {
		cout << "Yes";
	}
}