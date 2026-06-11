#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<vector<ll>>nabct(n+1, vector<ll>(5,0));
	for (int i = 0; i < n; i++) cin >> nabct.at(i+1).at(0);
	nabct.at(0).at(4) = 1;
	for (int i = 1; i < n + 1; i++) {
		ll m = 0;
		if (nabct.at(i).at(0) == nabct.at(i - 1).at(1))m++;
		if (nabct.at(i).at(0) == nabct.at(i - 1).at(2))m++;
		if (nabct.at(i).at(0) == nabct.at(i - 1).at(3))m++;
		nabct.at(i).at(4) = nabct.at(i - 1).at(4) * m;
		nabct.at(i).at(4) %= 1000000007;
		if (nabct.at(i).at(0) == nabct.at(i - 1).at(1)) {
			nabct.at(i).at(1) = nabct.at(i - 1).at(1) + 1;
			nabct.at(i).at(2) = nabct.at(i - 1).at(2);
			nabct.at(i).at(3) = nabct.at(i - 1).at(3);
		}
		else if (nabct.at(i).at(0) == nabct.at(i - 1).at(2)) {
			nabct.at(i).at(2) = nabct.at(i - 1).at(2) + 1;
			nabct.at(i).at(1) = nabct.at(i - 1).at(1);
			nabct.at(i).at(3) = nabct.at(i - 1).at(3);
		}
		else if (nabct.at(i).at(0) == nabct.at(i - 1).at(3)) {
			nabct.at(i).at(3) = nabct.at(i - 1).at(3) + 1;
			nabct.at(i).at(2) = nabct.at(i - 1).at(2);
			nabct.at(i).at(1) = nabct.at(i - 1).at(1);
		}
	}
	cout << nabct.at(n).at(4) << endl;

}