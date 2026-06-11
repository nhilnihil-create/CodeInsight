#include<bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	string sl = s.substr(0, s.size() / 2), sr = s.substr(s.size()/2 + 1);
	if(sl != sr) cout << "No" << endl;
	else {
		bool ok = true;
		for (int i = 0; i < sl.size() / 2; i++)
		{
			if(sl[i] != sl[sl.size()-1-i]) ok = false;
		}
		if(ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
