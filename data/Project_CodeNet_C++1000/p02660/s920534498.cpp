#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> pf(ll n){
    vector<pair<ll, ll>> res;
    for (ll i = 2; i*i <= n; i++){
        if (n%i != 0){
            continue;
        }
        else{
            ll ex = 0;
            while (n%i == 0){
                ex++;
                n /= i;
            }
            res.push_back({i, ex});
        }
    }
    if (n != 1){
        res.push_back({n, 1});
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> res = pf(n);
    ll ans = 0;
    for (auto p : res){
        ll c = 0;
        while (c*(c+1)/2 <= p.second){
            c++;
        }
        ans += c-1;
    }

    cout << ans << endl;

}