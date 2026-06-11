#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
	ll n, m;
    int a[3][3];
	ll i, j, k;
	ll ret = 0;
	
    for ( i = 0;i < 3; i++ ) {
        for ( j = 0; j < 3; j++ ) {
            cin >> a[i][j];
        }
    }
    cin >> n;
    vector<int> b(n);
    for ( i = 0; i < n; i++ ) {
        cin >> b[i];
    }
    
    for ( i = 0;i < 3; i++ ) {
        for ( j = 0; j < 3; j++ ) {
            for ( k = 0; k < n; k++ ) {
                if ( a[i][j] == b[k] ) {
                    a[i][j] = 0;
                }
            }
        }
    }

    for ( i = 0;i < 3; i++ ) {
        if ( (a[i][0] == 0) && (a[i][1] == 0) && (a[i][2] == 0) ) ret++;
    }
    for ( i = 0;i < 3; i++ ) {
        if ( (a[0][i] == 0) && (a[1][i] == 0) && (a[2][i] == 0) ) ret++;
    }
    if ( (a[0][0] == 0) && (a[1][1] == 0) && (a[2][2] == 0) ) ret++;
    if ( (a[2][0] == 0) && (a[1][1] == 0) && (a[2][0] == 0) ) ret++;
    cout << ((ret > 0) ? "Yes" : "No") << endl;
	
	
	return 0;
}