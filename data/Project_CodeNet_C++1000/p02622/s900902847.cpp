#include <bits/stdc++.h>

using namespace std;

int main(){
	string s, t;
	cin >> s >> t;
	int v = min(s.size(), t.size());
	int cnt = 0;
	for(int i = 0; i < v; i++){
		if(s[i] != t[i]) cnt++;
	}
	cout << cnt << endl;
}

