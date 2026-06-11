#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	if (s == "Sunny") cout << "Cloudy" << '\n';
	else if (s == "Rainy") cout << "Sunny" << '\n';
	else cout << "Rainy" << '\n';
	return 0;
}