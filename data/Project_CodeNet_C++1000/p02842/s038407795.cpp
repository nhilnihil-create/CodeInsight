#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n; cin >> n;
  	for (int i = 1; i <= n; i++) {
      	if ((int)(i * 1.08) == n) {
          	return cout << i << endl, 0;
        }
    }
  	cout << ":(" << endl;
    return 0;
}
