#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    int n;
    bool f = true;
    cin >> n;

    while ( n-- ) {
        int k ;
        cin >> k;

        if ( !( k % 2 ) && k % 6 && k % 10 ) f = false;
    }

    if ( f ) cout << "APPROVED";
    else cout << "DENIED";

    return 0;
}
