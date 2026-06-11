#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(ll i=0;i<n;i++)
#define mod 1000000007
#define oo 2000000000000000000LL
using namespace std;


void _sol(){
    ll n,d; cin >> n >> d;
    ll cnt= 0;
    forr(i,n){
        ll x,y; cin >> x >> y;
        if( x*x + y*y <= d*d ) cnt++;
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    _sol();
}
