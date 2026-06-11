#include <bits/stdc++.h>
#define fast_io ios :: sync_with_stdio(false);
using namespace std;

int main() {
	cout << fixed << setprecision(3);
	fast_io;
	string s; cin >> s;
	int cont = 0;
	for(int i = 0; i < s.size()/2; i++) {
		if(s[i] != s[s.size() - 1 - i]) {
			cont++;
		}
	}
	cout << cont;
	return 0;	
}