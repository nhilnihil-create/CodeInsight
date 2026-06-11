#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	vector<string> c = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	string s; cin >> s;
	int ans;
	if (s == c[0]) ans = 7;
	if (s == c[1]) ans = 6;
	if (s == c[2]) ans = 5;
	if (s == c[3]) ans = 4;
	if (s == c[4]) ans = 3;
	if (s == c[5]) ans = 2;
	if (s == c[6]) ans = 1;
    cout << ans << endl;
}
