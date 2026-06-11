#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(ll i=0;i<n;i++)
#define mod 1000000007
#define oo 2000000000000000000LL
using namespace std;

ll up(double x){
    if( x - (ll)x > 0 ) return (ll)x + 1;
    else return x;
}

bool check(ll a[], ll n, ll m, ll k){
    ll tot=0;
    forr(i,n) {
       if( a[i] > m )  tot += up((double)a[i]/m) - 1;
    }
    return tot<=k;
}

void _sol(){
    ll k; ll n; cin >> n >> k;
    ll a[n];
    forr(i,n) cin >> a[i];
    ll s = 1 , e = 1e10 , ans = -1;
    while(s <= e ){
        ll mid = (s+e)/2.0;
        if(check( a ,n ,mid,k )) ans = mid , e = mid-1;
        else s = mid+1;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    _sol();
}
