#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n; cin >> n; n %= 10;
  	cout << (n == 3 ? "bon" : (n == 0 || n == 1 || n == 6 || n == 8) ? "pon" : "hon") << endl;
  	return 0;
}
