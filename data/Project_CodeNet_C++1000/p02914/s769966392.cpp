#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
 

int n;
long long s, r;
   
int main ( void )
{
    ios::sync_with_stdio(false);
    cin.tie(0);   
    cin >> n;
	vector < long long > a ( n );
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> a [ i ];
        s ^= a [ i ];
    } //前缀 
    int number = 0;
    for ( int k = 60 - 1 ; k >= 0 ; k--) {
        long long l = 1LL << k; //long long int 
        if ( s & l ) continue;//比较i位上面的为1的是奇数还是偶数，奇数忽略，因为无论怎么划分两部分异或和在i位上都是一个1一个0 
        for ( int i = number ; i < n; i++ ) {
            if ( a [ i ] & l ) { //考虑偶数个1位如何构造最大,高位比低位重要 
                long long t = a [ i ];
                for ( int j = i + 1 ; j < n ; j++ ) {
                    if ( a [ j ] & l ) {
                        a [ j ] ^= t;
                    }
                }
                swap ( a [ number++ ] , a [ i ] );//a [ i ]用过了 
                if ( !( r & l ) ) r ^= t;
                break;
            }
        }
    }
	//r构造了一个能为1就为1的数
	s = r ^ s;
	r = s + r;
    cout << r << endl;

    return 0;
}