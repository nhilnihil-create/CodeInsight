#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1000000007;

int main(int, char**) {
	string s, t;
	cin >> s >> t;
	int a, b;
	cin >> a >> b;
	string u;
	cin >> u;
	if (u==s) a--;
	else b--;
	cout << a << " " << b << endl;
	return 0;
}