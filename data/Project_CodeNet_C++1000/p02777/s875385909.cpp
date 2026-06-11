#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
a = # of balls with the string s
b = # of balls with the string t
*/
string s, t, u;
int a, b;

int main() {
	cin >> s >> t;
	cin >> a >> b;
	cin >> u;
	if(u == s) a--;
	if(u == t) b--;
	cout << a << " " << b;
	return 0;
}
