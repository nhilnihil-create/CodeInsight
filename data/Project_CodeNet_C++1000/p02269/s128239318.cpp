#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int solve(){
	string c, s;
	map<string, bool> mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> c >> s;
		if (c == "insert") mp[s] = true;
		else {
			if (mp[s]) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
}

signed main(){
	solve();
}