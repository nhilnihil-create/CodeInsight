// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;

	if(s == "Sunny") cout << "Cloudy";
	else if(s=="Cloudy") cout << "Rainy";
	else cout << "Sunny";

	return 0;
}
