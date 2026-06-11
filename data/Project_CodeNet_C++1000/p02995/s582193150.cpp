#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

ll gcd (ll x, ll y){
    if(x % y == 0) return y ;
    ll r = x % y ;
    return gcd(y, r) ;
}

int main () {
    ll a, b, c, d ;
    cin >> a >> b >> c >> d ;
    ll tot = b - a + 1 ; 
    ll div1 = b / c - a / c ;
    ll div2 = b / d - a / d ; 
    if(a % c == 0){
        div1++ ; 
    }
    if(a % d == 0){
        div2++ ;
    }
    ll gd = gcd(c, d) ;
    gd = gd * (c / gd) * (d / gd) ; 
    ll div3 = b / gd - a / gd ; 
    if(a % gd == 0){
        div3++ ; 
    }
    ll de = div1 + div2 - div3 ;
    cout << tot - de << endl ; 
}

