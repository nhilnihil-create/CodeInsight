///                                                     ببِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
#include <bits/stdc++.h>
//#define off  exit( 0 )
//#define cn   continue
#define rt   return/*
#define sc   scanf
#define pr   printf
#define pb   push_back
#define pf   push_front
#define p_f  pop_front
#define p_b  pop_back
#define ff   first
#define ss   second
#define vec  vector
#define gcd  __gcd
#define pi   acos( -1 )*/
#define ll   long long
/*#define ld   long double
#define N    2256
#define M    1000000007
#define I    1000000000000000000
#define pdd  pair < ld, ld >
#define pll  pair < ll, ll >
#define pii  pair < int, int >
#define rep( a, b, c, d )  for( int a = b; a <= c; a += d )
#define rvv( a, b, c, d )  for( int a = b; a >= c; a -= d )
#define en                 printf( "\n" )
#define sqr( a )           a * a
#define all( c )           c.begin(), c.end()
#define srt( c )           sort( all( c ) )
#define rev( c )           reverse( all( c ) )
#define srtr( c )          sort( c.rbegin(), c.rend() )
#define numcounts          __builtin_popcount
#define mxn( x, y, z )     max( x, min( y, z ) )
#define mnx( x, y, z )     min( x, max( y, z ) )
const int dx[ ] = { 1, -1, 0, 0 };
const int dy[ ] = { 0, 0, -1, 1 };*/
using namespace std;
ll ttt = 1;
ll T1, T2, A1, A2, B1, B2, h1, h2, q, m, k;
void solve()
{
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    h1 = T1 * (A1 - B1);
    h2 = T2 * (A2 - B2);
    if(signbit(h1) == signbit(h2))
    {
        cout << 0 << endl;
        rt;
    }
    if(h1 >= 0)
    {
        h1 *= -1;
        h2 *= -1;
    }
    if(h1 + h2 == 0)
    {
        cout << "infinity" << endl;
        rt;
    }
    if(h1 + h2 < 0)
    {
        cout << 0 << endl;
        rt;
    }
    q = -h1 / (h1 + h2);
    m = -h1 % (h1 + h2);

    ll k = 2 * q;
    if(m)k ++;
    cout << k << endl;
}
int main()
{
    //sc( "%I64d", &ttt );
    for(int i = 0; i < ttt; i ++ )
        solve();
}
