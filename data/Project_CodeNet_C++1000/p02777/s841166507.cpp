#include <bits/stdc++.h>
using namespace std; 

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string u, s, t; 
	int a, b; 
	cin >> s >> t >> a >> b >> u;
	if(s==u)
		--a;
	else
		--b;
	cout << a << " " << b;
}
