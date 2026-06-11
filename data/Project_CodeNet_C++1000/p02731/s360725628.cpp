#include <bits/stdc++.h>
using namespace std;

int main() {
	double n; cin >> n;
	double ans = n / 3.0;
	ans = ans*ans*ans;
	
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}
