#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	string S;
	cin >> S;

	string ans = "";
	if (S == "Sunny") {
		ans = "Cloudy";
	}
	else if (S == "Cloudy") {
		ans = "Rainy";
	}
	else  if (S == "Rainy") {
		ans = "Sunny";
	}

	cout << ans << endl;
	return 0;
}
