#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
int main() {
	string s;
	cin >> s;
	bool flag = true;
	rep(i, s.size()) {
		if (i % 2 == 0 &&( s[i] != 'h'||s[i + 1] != 'i')) {
			flag = false;
		}
	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}