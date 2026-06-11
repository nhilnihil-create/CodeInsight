#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(0)





void solve() {

	string s;
	cin >> s;
	vector<string> v = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int pos = find(v.begin(), v.end(), s) - v.begin();
	if(pos == 6) {
		cout << 7;
		return;
	}
	cout << 6 - pos << "\n";
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	fix;
	solve();

	return 0;
}