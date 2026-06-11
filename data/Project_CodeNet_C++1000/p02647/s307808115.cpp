#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <limits>
#include <map>
using namespace std;

typedef long long ll;
#define rep1(i, n) for(ll i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(ll i = 0; i <=(ll)(n); i++)
int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1);
    rep1(i,n) cin >> a[i];
    ll mx = min(k,(ll)log(n)+1);
    rep1(ki,k){
        vector<ll> b(n+2);
        rep1(i,n){
            ll l = max(i-a[i], (ll)1);
            ll r = min(i+a[i]+1,n+1);
            b[l]++;
            b[r]--;
        }
        rep0(i,n-1) b[i+1] += b[i];
        b.pop_back();
        if(a == b)break;
        a = b;
    }
    rep1(i,n) cout << a[i] << endl;

}
/*
5 1
1 0 0 1 0

5 2
1 0 0 1 0
*/