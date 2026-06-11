#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	
	cout << a / b << " " << a % b << " " << fixed << setprecision(6) << (double)a / b << "\n";
	
	return 0;
}