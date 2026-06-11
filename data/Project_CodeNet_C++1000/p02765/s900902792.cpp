#include <bits/stdc++.h>
#define MODNum 1000000007
#define REP(type, i, a, b) for( type i = a; i < b; i++ )
typedef long long ll;

using namespace std;

int main (void) {
    int N, R, ans;
    cin >> N >> R;
    if ( N < 10 ) cout << R + 100 * ( 10 - N ) << endl;
    else cout << R << endl;
    return 0;
}
