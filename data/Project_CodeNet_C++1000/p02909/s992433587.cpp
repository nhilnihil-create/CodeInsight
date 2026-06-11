#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	vector<string> c = { "Sunny", "Cloudy", "Rainy" };
	if (s == c[0]) s = c[1];
	else if (s == c[1]) s = c[2];
	else s = c[0];
	cout << s << endl;
	return 0;
}