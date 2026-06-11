#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
	ll n, m;
	ll i, j, k;
	ll ret = 0;
	ll h, w;
	
    cin >> h >>w;

    if ( ( h == 1) || (w == 1) ) {
        cout << 1 << endl;
    }
    else {
        cout << (((h * w % 2) == 1) ? (h * w / 2 + 1) : h * w / 2) <<endl;
    }
	return 0;
}
