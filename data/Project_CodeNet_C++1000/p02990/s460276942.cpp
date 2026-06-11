#include<bits/stdc++.h>
#include <complex>
#define ll long long
#define ld long double
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0) ; cin.tie(0) ;
#define pi acos(-1)
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(),(a).real()))
#define vec(a,b) ((b)-(a))
#define lenght(a) (hypot((a).imag(),(a).real()))
#define normalize(a) (a)/length(a)
#define point complex<long double>
#define dP(a,b)((conj(a)*(b)).real())
#define cP(a,b)((conj(a)*(b)).imag())
#define same(p1,p2)  (dP(vec(p1,p2),vec(p1,p2)) < EPS)
#define lengthsqr(p)   dP(p,p)
#define rotate0(p,ang)  ((p)*exp(point(0,ang)))
#define rotataA(p,ang,about) (rotate0(vec(about,p),ang)+about)
#define reflect0(v,m) (conj((v)/(m))*(m))
const ld EPS = (1e-10);
using namespace std;
const int N = 2e3+40, mod = 1e9+7;
ll fact[N], INV[N] ;
ll fp (ll b, ll p)
{
    if ( p == 0 )
        return 1 ;
    ll temp = fp(b,p/2)%mod ;
    temp = (temp*temp)%mod ;
    if ( p%2)
        temp = (temp *b )%mod ;
    return temp;
}
void pre()
{
    fact[0] = 1 ;
    INV[0] = 1 ;
    for ( int i = 1 ; i <= N ; i++)
    {
        fact[i] = (fact[i-1]*i)%mod ;
        INV[i] = fp(fact[i],mod-2);
    }
    return ;
}
ll nCr(ll n, ll r)
{
    if ( r > n)
            return 0 ;
    if ( n == r || r == 0 )
            return 1 ;
    return (((fact[n] * INV[n-r])%mod) * INV[r])%mod;
}
int main()
{
    Tsetso
    pre();
    int n, k ;
    cin >> n >> k ;
    for ( int i = 1 ; i <= k ; i++)
        cout << (nCr(n-k+1,i)*nCr(k-1,i-1))%mod << endl;
}
