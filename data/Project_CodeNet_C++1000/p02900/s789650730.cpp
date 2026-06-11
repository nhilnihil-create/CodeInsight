#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> Pair;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll INFL = 1e18;

vector<pair<ll,int>> factors(ll n){
    vector<pair<ll,int>> res;
    for(ll i=2; i*i<=n; i++){
        if(n%i) continue;
        res.emplace_back(i,0);
        while(n%i == 0){
            n/=i;
            res.back().second++;
        }
    }
    if(n != 1) res.emplace_back(n,1);
    return res;
}

int main(){
    ll a,b;
    cin >> a >> b;
    ll g = __gcd(a,b);
    vector<pair<ll,int>> f = factors(g);
    ll ans = f.size() + 1;
    cout << ans << endl;
    return 0;
}