#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x ;
    cin >> x ;
    int num = x % 100 ;
    x /= 100 ;
    if ( 5 * x >= num ) cout << 1 << endl ;  
    else cout << 0 << endl ;  
    return 0;
}
