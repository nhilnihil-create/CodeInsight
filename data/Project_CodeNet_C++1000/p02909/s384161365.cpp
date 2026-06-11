#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	string arr[] = {"Sunny", "Cloudy", "Rainy"};
	string s;
	cin >> s;
	auto pos = find(arr, arr + 3, s) - arr;
	cout << arr[(pos + 1) % 3];
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}