#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    if((a - b) % 2){
        ll mn = min(a - 1, n - b);
        if(mn == a - 1){
            cout << (b - (1 - a)) / 2;
        }else{
            cout << (2 * n + 1 - b - a) / 2;
        }
    }else{
        cout << (b - a) / 2;
    }
}