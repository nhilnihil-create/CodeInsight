#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string  S, T;
    int     size, ans = 0;
    
    cin >> S >> T;
    
    size = S.size();
    for ( int ii = 0; ii < size; ii++ ) {
        if ( S[ii] != T[ii] ) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}