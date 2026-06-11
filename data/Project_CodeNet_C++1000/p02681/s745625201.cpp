#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false); 

	string s, t;
	cin >> s;
	cin >> t;
	bool ok = true;
	for (int i = 0; i < s.size(); i++){
		if (s[i] != t[i]){
			ok = false;
		}
	}

	if (ok){
		cout << "Yes";
	} else {
		cout << "No";
	}




}