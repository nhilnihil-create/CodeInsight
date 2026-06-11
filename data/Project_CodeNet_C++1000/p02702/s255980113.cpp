#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <climits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <stack>
#define mod 2019
using namespace std ;
int binaryexpo( int A , int B ){
    int ans = 1 ;
    while( B ){
        if( B & 1 )
            ans = ( ans % mod * A % mod ) % mod ;
        A = ( A % mod * A % mod ) % mod ;
        B >>= 1 ;
    }
    return ans ;
}
int main(){
    string str ; cin >> str ;
    map<int ,long long int> m ;
    m[0] = 1;
    int rem = 0 ;
    long long int ans = 0 ;
    for( int i = (int)str.length() - 1  ; i >= 0 ; i-- ){
        rem = rem + ( str[i] - '0' ) * binaryexpo(10, (int)str.length() - i + 1 )  ;
        rem %= mod ;
        if( m.find(rem) != m.end() )
            ans += m[rem] ;
        m[rem]++ ;
    }
    cout << endl;
    cout << ans << endl ;
    return 0 ;
}
