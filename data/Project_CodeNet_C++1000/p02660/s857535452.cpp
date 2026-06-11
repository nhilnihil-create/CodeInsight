#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

map<ll, ll> factor(ll n){
    map<ll, ll> res;

    for (ll i = 2; i*i <= n; ++i) {
        while(n % i == 0){
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;

    return res;
}

int main(){

    ll n;
    cin >> n;

    map<ll, ll> mp = factor(n);
    ll ans = 0;
    for(auto q : mp){
        //cout << q.first << " " << q.second << "\n";
        ll cnt = 0;
        while(cnt * (cnt + 1) / 2 < q.second){
            cnt++;
        }
        if(cnt * (cnt + 1) / 2 != q.second) cnt--;
        ans += cnt;
        //cout << cnt << "\n";
    }

    cout << ans << "\n";

    return 0;
}
