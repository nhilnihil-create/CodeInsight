#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	string s;
	cin >> s;
	if(s[2] == s[3] && s[4] == s[5]){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}