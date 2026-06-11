#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string s;
	cin >> s;

	int ans = 0;
	if (s=="SUN"){
		ans = 7;
	}
	if (s=="MON"){
		ans = 6;
	}
	if (s=="TUE"){
		ans = 5;
	}
	if (s=="WED"){
		ans = 4;
	}
	if (s=="THU"){
		ans = 3;
	}
	if (s=="FRI"){
		ans = 2;
	}
	if (s=="SAT"){
		ans = 1;
	}



	cout << ans << "\n";

	return 0;
}
