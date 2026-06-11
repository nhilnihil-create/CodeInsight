#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int l , r , d ;
    cin >> l >> r >> d ;
    l-- ;
    l /= d ;
    r /= d ;
    cout << r-l << endl ;
}
