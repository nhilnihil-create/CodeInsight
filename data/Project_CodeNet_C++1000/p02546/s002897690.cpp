#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int ans;

void solve(void){
	string s;
	cin >> s;
	if(s.size() == 1){
		if(s.back() == 's'){
			s += "es";
		}
		else{
			s += "s";
		}
		cout << s << endl;
		return;
	}
	if(s[s.size()-1] == 's'){
		s += "es";
	}
	else{
		s += "s";
	}
	 cout << s << endl; 
}

signed main() {
int t = 1;
// cin >> t;    
	while(t--)
    solve();

    return 0;
}
