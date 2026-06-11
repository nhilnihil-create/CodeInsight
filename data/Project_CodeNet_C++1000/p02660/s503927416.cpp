#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const ll M = 1000000000000000000;

vector<pair<ll,ll>> prime_factorize(ll n){
    vector<pair<ll,ll>> res;
    for(ll a = 2; a * a <= n; a++){
        if(n % a != 0) continue;
        ll ex = 0;
        while(n % a == 0){
            ex++;
            n /= a;
        }
        res.push_back({a,ex});
    }
    if(n != 1) res.push_back({n,1});
    return res;
}

int main(){
    ll n; cin >> n;
    const auto &res = prime_factorize(n);
    ll ans = 0;
    for(auto p:res){
        ll i=1;
        while(1){
            if(i*(i+1)/2<=p.second && p.second<(i+1)*(i+2)/2){
                ans += i;
                break;
            }
            i++;
        }
    }
    cout << ans << endl;
}