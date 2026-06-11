#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
typedef long long ll;
ll gcd(ll a, ll b)
{
   if (b == 0)
   {
       return a;
   }
    return gcd(b, a%b);
}

vector<ll> factorize(ll n){
    vector<ll> res;
    for(ll i = 2; i*i<=n; i++){
        if(n%i)continue;
        while (n%i == 0) {
            n /= i;
        }
        res.push_back(i);
    }
    if(n!=1) res.push_back(n);
    return res;
}

int main() {
    ll a,b;
    cin >> a >> b;
    ll gcdn = gcd(a, b);
    auto f = factorize(gcdn);
    ll ans = f.size() + 1;
    cout << ans << endl;
    return 0;
}
