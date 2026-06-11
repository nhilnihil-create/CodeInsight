#include <iostream>
#include <cstring>
using namespace std;

const int size = 2*123456+1;
bool p[size];
int dp[size];

int main() {
    memset( p, false, sizeof(p) );
    for ( int i = 3; i <= size; i += 2 ) {
        p[i] = true;
    }
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for ( int i = 3; i <= size; i++ ) {
        dp[i] = dp[i-1];
        if ( !p[i] ) continue;
        dp[i]++;
        for ( int j = i+i; j <= size; j += i ) {
            p[j] = false;
        }
    }

    int n;
    while ( cin >> n && n ) {
        cout << dp[2*n] - dp[n] << endl;
    }
    return 0;
}