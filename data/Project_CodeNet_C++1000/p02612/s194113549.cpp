#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n; cin >> n;
  	cout << (1000 - n % 1000) % 1000 << endl;
    return 0;
}
