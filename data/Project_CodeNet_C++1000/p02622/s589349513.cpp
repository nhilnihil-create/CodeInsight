#include <bits/stdc++.h>
using namespace std;

int a;

int main() {
	string s, g;
	cin >> s >> g;
	int jum = 0;
	for(int k = 0; k<s.length(); k++){
		if(s[k]!=g[k]){
			jum++;
		}
	}
	cout << jum << '\n';
}