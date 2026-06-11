#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl

vector<ll> enumerate_divisors(ll n){
    vector<ll> res;
    for(ll i = 1; i * i <= n; ++i){
        if(n % i == 0){
            res.push_back(i);
            if(n/i != i){res.push_back(n/i);}
        }
    }
    sort(res.begin(), res.end());
    return res;
}

vector<pll> prime_factorize(ll n){
    vector<pll> res;
    for(ll a = 2; a * a <= n; ++a){
        if(n % a != 0){continue;}
        ll ex = 0;

        while(n % a == 0){
            ++ex;
            n /= a;
        }

        res.push_back({a, ex});
    }

    if (n != 1) res.push_back({n, 1});
    return res;
}

int main(){
    ll n;
    cin >> n;
    ll ans = 0;

    vector<ll> divisors = enumerate_divisors(n);
    vector<pll> factorized = prime_factorize(n-1);

    for(auto k: divisors){
        if(k==1){continue;}
        ll num = n;
        while(num >= k){
            if(num%k == 0){
                num /= k;
            }else{
                num %= k;
            }
            if(num==1){ans++;}
        }
    }

    ll tmpval = 1;
    for(auto f: factorized){
        tmpval *= f.second+1;
    }
    tmpval--;

    ans += tmpval;

    cout << ans << endl;
    return 0;

}
