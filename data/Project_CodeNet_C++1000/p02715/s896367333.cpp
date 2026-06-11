#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
ll MOD = 1e9 + 7;

ll mul(ll a, ll b) { return a * b % MOD; }
 
ll add(ll a, ll b) { return (a + b) % MOD; }
 
ll sub(ll a, ll b) { return (a - b + MOD) % MOD; }

ll my_pow(ll a, ll b, ll r = 1){
    if (b != 1){
        if (b%2 == 1){r = mul(r,a);}
        return my_pow(mul(a,a), b/2, r);
    }else{
        return mul(r, a);
    }
}


int main(){
    ll n, k, ans=0;
    cin >> n >> k;
    vector<ll> arr(k+1,0);
    for(ll i=k; i>0; i--){
        arr[i] = my_pow((k/i),n);
        for(ll j = 2 * i; j <= k; j += i){
            arr[i] -= arr[j];
        }
    }
    for(ll i=1; i<=k; i++){
        ans = add(ans, mul(arr[i],i));
    }
    cout << ans << "\n";
    return 0;
}