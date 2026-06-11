#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
bool is_prime(ll n){
    if(n <= 1)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    for(ll i = 3; i * i <= n; i += 2)
        if(n % i == 0)  
            return false;
    return true;
}
int main(){
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    ll ans = 1;
    for(ll i = 2; i * i <= g; i++){
        if(g % i == 0){
           if(is_prime(i))
                ans++;
            if(is_prime(g / i))
                ans++;
        }
    }
    if(is_prime(g))
        ans++;
    cout << ans << endl;
    return 0;
}
