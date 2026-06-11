#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<numeric>
#include<algorithm>
#include<tuple>
#include<cmath>
#include <iomanip>

typedef unsigned long long ull;
typedef long long ll;

ll DENOM = 1000000000LL + 7LL;

using namespace std;

ll n, m, k;
ll h, w;


int main(){
    ll x;
    cin >> x;
    ll mx = 110000;
    vector<ll> is_prime(mx+1, true);
    for (ll i=2; i<mx; ++i){
        if(! is_prime[i]) continue;
        for(ll j=2; j*i <= mx; ++j){
            is_prime[i*j] = false;
        }
    }
    for(ll i=x; i<mx; ++i){
        if(is_prime[i]){
            cout << i << endl;
            break;
        }
    }
    return 0;
}