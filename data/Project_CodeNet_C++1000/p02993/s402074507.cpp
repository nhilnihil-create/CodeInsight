#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	string s;
	cin >> s;

	bool res = false;
	rep(i, s.size()-1){
		if(s.at(i) == s.at(i+1)) res = true;
	}
	
	if(res) cout << "Bad" << endl;
	else cout << "Good" << endl;

	return 0;
}