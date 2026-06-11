#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	string s;
	cin >> s;

	bool ans = false;
	sort(s.begin(), s.end());
	if(s.at(0) == s.at(1) && s.at(2) == s.at(3) && s.at(0) != s.at(2))
		cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}