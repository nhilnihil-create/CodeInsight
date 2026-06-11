#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Y cout << "YES\n"
#define N cout << "NO\n"
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define R(i,n) for(int i = 0 ; i < n ; i++)

int main()
{
    ll n , a , ans = 0 , c = 0 , d , e , f , b ;
    cin >> n >> a >> b ;
    if( (b-a)%2 )
    {
        c = n - a ;
        d = a - 1 ;
        e = n - b ;
        f = b - 1 ;
        if( c < f )
        {
            ans = c ;
        }
        else
        {
            ans = f ;
        }
        e = ( (n - (a+e+1) ) /2 ) + (e + 1) ;
        if(ans > e)
        {
            ans = e ;
        } 
        d = ( ( b - (d+2) ) /2 ) + (d + 1) ;
        if(ans > d)
        {
            ans = d ;
        }
        cout << ans << endl ;
    }
    else
    {
        ans = b-a ;
        ans /= 2 ;
        cout << ans << endl ;
    }
}