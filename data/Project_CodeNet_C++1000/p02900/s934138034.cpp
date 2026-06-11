#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;


ll gcd(ll x,ll y){return y ? gcd(y,x % y) : x;}

vector<pair<ll,int>> factorize(ll n){
    vector<pair<ll,int>> res;
    for(ll i = 2;i * i <= n;i++){
        if(n%i) continue;
        res.emplace_back(i,0);
        while(n%i == 0){
            n /= i;
            res.back().second++;
        }
    }
    if(n!=1)res.emplace_back(n,1);
    return res;
}

int main(){
    ll a,b;
    cin >> a >> b;
    ll g = gcd(a,b);
    auto f = factorize(g);
    ll ans = f.size() + 1;
    cout << ans << endl;
    // set<ll> s;
    // s.insert(1);
    // for(ll i = 2;i * i <= g;i++){
    //     if(g == 1) break;
    //     while(g % i == 0){
    //         g /= i;
    //         s.insert(i);
    //     }
    // }
    // if(g!=1)s.insert(g);
    // cout << s.size() << endl;
    
}