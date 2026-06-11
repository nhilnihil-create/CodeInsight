#include <bits/stdc++.h>
#define off  exit( 0 )
#define cn   continue
#define rt   return
#define sc   scanf
#define pr   printf
#define pb   push_back
#define pf   push_front
#define p_f  pop_front
#define p_b  pop_back
#define ff   first
#define ss   second
#define ll   long long
#define ld   long double
#define N    356
#define M    1000000007
#define I    1000000000000000000
#define pdd  pair < ld, ld >
#define pll  pair < ll, ll >
#define pii  pair < int, int >
#define sqr( a )           a * a
#define all( c )           c.begin(), c.end()
#define srt( c )           sort( all( c ) )
#define rev( c )           reverse( all( c ) )
#define srtr( c )          sort( c.rbegin(), c.rend() );
using namespace std;
ll n, a, b, x, y;
void solve()
{
    cin >> n;
    for( int i = 1; i <= n; i ++ )
    {
        cin >> a >> b;
        x += b;
        y += a * b;

    }
    x --;
    y --;
    x += y / 9;
    cout << x;
}
int main()
{
    ll tt = 1;
    //sc( "%d", &tt );
    for( ll i = 1; i <= tt; i ++ )
    {
        solve();
    }
}










