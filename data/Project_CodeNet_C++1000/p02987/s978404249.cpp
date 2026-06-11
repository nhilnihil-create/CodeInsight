#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x;
	for(int i = 0;i < n;i++){
		int ia;
		cin >> ia;
		x.push_back(ia);
	}
	return x;
}
int main(){
	string s;
	cin >> s;
	if(s[0] == s[1] && s[2] == s[3] && s[0] != s[2]){
		cout << "Yes" << endl;
	}else if(s[0] == s[2] && s[1] == s[3] && s[0] != s[3]){
		cout << "Yes" << endl;
	}else if(s[0] == s[3] && s[1] == s[2] && s[0] != s[1]){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}