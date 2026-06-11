#include <bits/stdc++.h>
using namespace std;

int main(void){
    long n;
    cin >> n;
    
    if( n&1 ){
        cout << 0 << endl;
        return 0;
    }

    long nTmp = n/2;
    long ans = 0, multiple = 5;
    while( nTmp >= multiple ){
        ans += nTmp / multiple;
        multiple *= 5;
    }

    cout << ans << endl;

    return 0;
}
