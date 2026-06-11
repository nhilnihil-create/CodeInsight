#include <bits/stdc++.h>
#define fast_io ios :: sync_with_stdio(false); cin.tie(NULL)
using namespace std;


int main() {
	string s;
	string aux;
	cin >> s;
	aux = s;
	int count = 0;
	reverse(aux.begin(), aux.end());
	for (int i = 0; i<s.size(); i++) {
		if (s[i] != aux[i])count++;
	}
	cout << count/2 << "\n";

	
	return(0);
}