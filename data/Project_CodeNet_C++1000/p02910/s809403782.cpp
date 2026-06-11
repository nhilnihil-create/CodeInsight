#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string s;
	cin >> s;

	bool OK = true;
	for (int ii = 0; ii < s.size(); ++ii){
		if (ii % 2 == 1){
			if ( (s[ii]!='L') && (s[ii]!='U') && (s[ii]!='D')){
				OK = false;
				break;
			}
		} else{
			if ( (s[ii]!='R') && (s[ii]!='U') && (s[ii]!='D')){
				OK = false;
				break;
			}

		}
	}

	if (OK){
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";		
	}


	return 0;
}
