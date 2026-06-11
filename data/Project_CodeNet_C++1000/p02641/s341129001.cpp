#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;

int main() {
    int l[100 + 2];
    int X, N;
    int a1 = 101, a2 = 101, ans;
    
    memset(l, 0x00, sizeof(l));
    
    cin >> X >> N;
    for ( int ii = 0; ii < N; ii++ ) {
        int p; cin >> p;
        l[p] = 1;
    }
    for ( int ii = X; ii >= 0; ii-- ) {
        if ( l[ii] == 1 ) {
            continue;
        }
        int tmp = X - ii;
        if ( tmp < a1 ) {
            a1 = tmp;
        }
    }
    for ( int ii = X; ii < 102; ii++ ) {
        if ( l[ii] == 1 ) {
            continue;
        }
        int tmp = ii - X;
        if ( tmp < a2 ) {
            a2 = tmp;
        }
    }
    if ( a1 == a2 ) {
        ans = X - a1;
    } else if ( a1 > a2 ) {
        ans = X + a2;
    } else {
        ans = X - a1;
    }
    cout << ans << endl;
    return 0;
}