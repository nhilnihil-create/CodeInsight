#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n; cin >> n;
  	while (n) {
      	if (n % 10 == 7) {
          	return cout << "Yes" << endl, 0;
        }
      	n /= 10;
    }
  	cout << "No" << endl;
  	return 0;
}
