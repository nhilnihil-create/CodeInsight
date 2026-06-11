#include <bits/stdc++.h>
using namespace std;

string s, t;
int cnt;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin >> s >> t;
	cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != t[i]) cnt++;
	}
	cout << cnt;
}