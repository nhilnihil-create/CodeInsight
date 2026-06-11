#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	string s;
	cin >> s;
	
	bool res = true;
	rep(i, s.size()){
		if(i%2 == 0 && s.at(i) == 'L'){
			res = false;
		}else if(i%2 == 1 && s.at(i) == 'R'){
			res = false;
		}
	}

	if(res) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
