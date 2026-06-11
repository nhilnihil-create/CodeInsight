#include <bits/stdc++.h>
using namespace std;
 
signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	for(int i = 0; i < s.size(); i++){
		cout << (char)((s[i] - 'A' + n) % 26 + 'A');
	}
}
