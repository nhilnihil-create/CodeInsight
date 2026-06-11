#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r = 0, w = 0;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++){
		if (s[i] == 'W') w++;
		else r++;
	}
	int er = 0;
	for (int i = 0; i < r; i++)
		if(s[i] == 'W') er++;
	cout << er << endl;
	return 0;
}