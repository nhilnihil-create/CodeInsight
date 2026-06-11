#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

using ll = long long;

void read();
template<typename First, typename... Rest> void read(First& first, Rest&... rest);
void write();
template<typename First, typename... Rest> void write(First first, Rest... rest);
template<typename T> void write_vec(vector<T>& v, char divider);

constexpr ll MOD = 1000000007;

ll modpow(ll n, ll r, ll mod) {
    if(r == 0) return 1;
    if(n == 0) return 0;
    if(r % 2 == 0) {
        ll tmp = modpow(n, r / 2, mod);
        return tmp * tmp % mod;
    }
    else {
        return n * modpow(n, r - 1, mod) % mod;
    }
}

ll modcomb(ll n, ll r, ll mod){
    ll u = 1;
    for(ll i = n; i > n - r; i--){
        u *= i;
        u %= mod;
    }
    ll d = 1;
    for(ll i = r; i > 0; i--){
        d *= i;
        d %= mod;
    }
    return u * modpow(d, mod - 2, mod) % mod;
}

int main(){
    ll n, a, b;
    read(n, a, b);
    ll ans = modpow(2, n, MOD);
    ans = (ans - modcomb(n, a, MOD) + MOD) % MOD;
    ans = (ans - modcomb(n, b, MOD) + MOD) % MOD;
    write(ans - 1);
    return 0;
}

//配列以外の入力を受け取る
void read(){

}
template<typename First, typename... Rest>
void read(First& first, Rest&... rest){
    cin >> first;
    read(rest...);
}
//
//配列以外を出力する
void write(){

}
template<typename First, typename... Rest>
void write(First first, Rest... rest){
    cout << first << " ";
    write(rest...);
}
//
//配列を区切って出力する
template<typename T>
void write_vec(vector<T>& v, char divider){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << divider;
    }
}
//