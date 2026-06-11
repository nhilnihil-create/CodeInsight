#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
	ll n, x;
	ll i, j, k;
	ll ret = 0;
	
	cin >> n;
	
    for ( i = 0; i < 50000; i++ ) {
        if ( i <= n) {
            if ( i * 108 / 100 == n ) {
                cout << i << endl;
                return 0;
            }
        }
        else {
            cout << ":(" << endl;
            return 0;
        }
    }
	return 0;
}
