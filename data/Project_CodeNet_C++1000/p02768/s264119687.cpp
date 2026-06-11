#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7/*998244353*/;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll sum = mod_pow(2, n, MOD) - 1;
    ll x_a = 1, y_a = 1, x_b = 1, y_b = 1;
    for(int i = 0; i < a; i++){
        x_a = x_a * (n - i) % MOD;
        y_a = y_a * (i + 1) % MOD;
    }
    for(int i = 0; i < b; i++){
        x_b = x_b * (n - i) % MOD;
        y_b = y_b * (i + 1) % MOD;
    }
    sum = sum - x_a * mod_inv(y_a, MOD) % MOD - x_b * mod_inv(y_b, MOD) % MOD + 2 * MOD;
    sum %= MOD;
    cout << sum;
}

/*⠀⠀⠀⠀⠀⢀⣀⣀⣀    
⠀⠀⠀⠰⡿⠿⠛⠛⠻⠿⣷
⠀⠀⠀⠀⠀⠀⣀⣄⡀⠀⠀⠀⠀⢀⣀⣀⣤⣄⣀⡀
⠀⠀⠀⠀⠀⢸⣿⣿⣷⠀⠀⠀⠀⠛⠛⣿⣿⣿⡛⠿⠷
⠀⠀⠀⠀⠀⠘⠿⠿⠋⠀⠀⠀⠀⠀⠀⣿⣿⣿⠇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁

⠀⠀⠀⠀⣿⣷⣄⠀⢶⣶⣷⣶⣶⣤⣀
⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠈⠙⠻⠗
⠀⠀⠀⣰⣿⣿⣿⠀⠀⠀⠀⢀⣀⣠⣤⣴⣶⡄
⠀⣠⣾⣿⣿⣿⣥⣶⣶⣿⣿⣿⣿⣿⠿⠿⠛⠃
⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄
⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡁
⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁
⠀⠀⠛⢿⣿⣿⣿⣿⣿⣿⡿⠟
⠀⠀⠀⠀⠀⠉⠉⠉
*/

//library//
ll mod_fact(ll a, ll mod){
    ll ans = 1;
    while(a > 1){
        ans = ans * a % mod;
        a--;
    }
    return ans; 
}
ll mod_pow(ll a, ll b, ll mod){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
ll mod_inv(ll a, ll mod){
    return mod_pow(a, mod - 2, mod);
}
ll gcd(ll a, ll b){
    while(a % b){
        return gcd(b, a % b);
    }
    return b;
}
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
