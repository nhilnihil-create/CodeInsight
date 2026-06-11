#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int red;
	string s;
	cin >> red >> s;

	if(red >= 3200)
		cout << s;
	else
		cout << "red";
	return 0;
}