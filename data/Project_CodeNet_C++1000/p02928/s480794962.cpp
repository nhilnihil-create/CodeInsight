#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

ll modpow ( ll a, ll n ) {
    ll res = 1;
    while ( n > 0 ) {
        if ( n & 1 ) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll modinv ( ll a ) {
    return modpow(a, mod - 2);
} 

int main(){
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    vector<ll> a_2n(n*2);
    rep(i, n) {
        cin >> a[i];
        a_2n[i] = a[i];
        a_2n[i+n] = a[i];
    }

    vector<ll> tento(n, 0);
    ll tento_sum = 0;
    rep(i, n) {
        for ( int j = i + 1; j < n; ++j ) {
            if ( a[i] > a[j] ) {
                tento[i] = ( tento[i] + 1 ) % mod;
                tento_sum = ( tento_sum + 1 ) % mod;
            }
        }
    }

//    for ( auto tmp_num : tento ) {
//        cout << tmp_num << endl;
//    }

    vector<ll> tento_diff(n, 0);
    rep(i, n) {
        ll tmp_tento_num = 0;
        for ( int j = i + 1; j < n * 2; ++j ) {
            if ( a[i] > a_2n[j] ) {
                tmp_tento_num = ( tmp_tento_num + 1 ) % mod;
            }
        }
//        cout << tmp_tento_num << endl;
        tento_diff[i] = ( tmp_tento_num - tento[i] ) % mod;
    }

//    for ( auto tmp_num : tento_diff ) {
//        cout << tmp_num << endl;
//    }

    ll ans = 0;
    ll add_num = 0;
    rep(i, n) {
        add_num = ( tento_diff[i] * k % mod * ( k - 1 ) % mod * modinv(2) + tento[i] * k % mod ) % mod;
        ans = ( ans + add_num ) % mod;
//        cout << ans << endl;
    }

    cout << ans << endl;

    return 0;
}