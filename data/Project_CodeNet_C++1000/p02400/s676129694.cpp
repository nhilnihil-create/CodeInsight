#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
const double PI = acos(-1.0);

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	double r;
	cin >> r;
	
	cout << fixed << setprecision(6) << r * r * PI << " " << 2 * r * PI << "\n";
	
	return 0;
}