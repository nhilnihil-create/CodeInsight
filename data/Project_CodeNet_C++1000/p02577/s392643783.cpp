#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<typeinfo>


#define ll long long

using namespace std;
inline ll keta(ll n) {
	if (n < 10) return n;

	return keta(n / 10) + n % 10;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s;

	cin >> s;
	int sum = 0;

	for (auto x : s) sum += x -'0';

	if (sum % 9 == 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}