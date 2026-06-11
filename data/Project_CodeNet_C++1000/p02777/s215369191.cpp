#include <iostream>
using namespace std;

int main() {
	string s, str;
	cin >> s >> str;
	int a, b;
	cin >> a >> b;
	string u;
	cin >> u;
	if(u == s)
		--a;
	else
		--b;
	cout << a << ' ' << b;
	
}