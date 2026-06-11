#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int64_t D, T, S ;
    ios::sync_with_stdio(false) ;
    while(cin >> D >> T>> S) {
        cout << ((D <= T*S)?"Yes":"No") << endl ;
    }
}
