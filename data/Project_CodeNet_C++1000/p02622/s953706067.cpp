#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	string a, b; cin >> a >> b;
  	int r = 0;
  	for (int i = 0; i < a.size(); i++) {
        r += (a[i] != b[i]);
    }
  	cout << r << endl;
    return 0;
}
