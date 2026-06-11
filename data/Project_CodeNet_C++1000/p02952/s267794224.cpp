#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long  ans = 0;
    if ( 1 <= n && n < 10 ) {
        ans = n;
    }
    else if ( 10 <= n && n < 100 ) {
        ans = 9;
    }
    else if ( 100 <= n && n < 1000 ) {
        ans += 9 + n - 100 + 1;
    }
    else if ( 1000 <= n && n < 10000 ) {
        ans += 9 + 900;
    }
    else if ( 10000 <= n && n < 100000 ) {
        ans += 9 + 900 + n - 10000 + 1;
    }
    else {
        ans += 90909;
    }

    cout << ans << endl;
}