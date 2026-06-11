#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpi = vector<pii>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int x;
	cin >> x;
	if (x >= 400 && x < 600) cout << "8\n";
	else if (x >= 600 && x < 800) cout << "7\n";
	else if (x >= 800 && x < 1000) cout << "6\n";
	else if (x >= 1000 && x < 1200) cout << "5\n";
	else if (x >= 1200 && x < 1400) cout << "4\n";
	else if (x >= 1400 && x < 1600) cout << "3\n";
	else if (x >= 1600 && x < 1800) cout << "2\n";
	else cout << "1\n";


    return 0;
}