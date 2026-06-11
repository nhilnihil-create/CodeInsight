#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

long int modpow(long int a, long int n, long int mod) {
    long int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

long int modcomb(long int a, long int b, long int mod){
    long int res = 1;
    for(long int i = a; i > a - b; i--){
        res *= i % mod;
        res %= mod;
    }
    res %= mod;
    for(long int i = 1; i <= b; i++){
        long int i_inv = modpow(i, mod - 2, mod);
        res *= i_inv % mod;
        res %= mod;
    }
    res %= mod;
    // cout << res << endl;
    return res;
}


int main(){
    int x, y;
    cin >> x >> y;
    int a = 2 * x - y, b = 2 * y - x;
    if(a < 0 || b < 0 || a % 3 != 0 || b % 3 != 0){
        cout << 0 << endl;
        return 0;
    }
    int h = a / 3, w = b / 3;
    ll ans = modcomb((ll)(h+w), (ll)w, mod);
    cout << ans << endl;
}