#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
#define check cout<<"?\n";
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    ll n; cin >> n;
    ll mxd = 1;
    for(ll i = 2; i * i <= n; ++i){
        if(n % i == 0){
            mxd = max(mxd, i);
        }
    }
    ll sed = n/mxd;
    cout << sed + mxd - 2 << '\n';
    return 0;
}