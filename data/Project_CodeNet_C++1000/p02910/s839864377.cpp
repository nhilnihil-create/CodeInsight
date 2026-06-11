#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;

signed main(){
	string s; cin >> s;
	bool ok = true;
	for(int i = 0; i < s.size(); i++){
		char c = s[i];
		if(i % 2 == 0) if(c == 'L') ok = false;
		if(i % 2 == 1) if(c == 'R') ok = false;
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}
