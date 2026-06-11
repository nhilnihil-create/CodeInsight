#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(), a.end());
	string ans = "No";
	if ((a[0] == a[1] && a[1] != a[2]) || (a[2] == a[1] && a[1] != a[0])) ans = "Yes";
	cout << ans << endl;
    return 0;
}