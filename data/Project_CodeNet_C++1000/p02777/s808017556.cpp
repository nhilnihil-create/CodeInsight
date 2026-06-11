#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(10)





void solve() {

	map<string, int> mp;
	string a, b;
	cin >> a >> b;
	int x, y;
	cin >> x >> y;
	mp[a] = x;
	mp[b] = y;
	string s;
	cin >> s;
	mp[s]--;
	cout << mp[a] << " " << mp[b] << "\n";




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();

	return 0;
}