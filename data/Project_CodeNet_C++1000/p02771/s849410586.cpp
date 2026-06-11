#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a[5];
	cin >> a[1] >> a[2] >> a[3];
	sort(a+1, a+4);
	if (a[1] == a[2] && a[3] != a[1]) {
		cout << "Yes";
		return 0;
	}
	if (a[2] == a[3] && a[1] != a[2]) {
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}