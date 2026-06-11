#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // 指数
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        // その結果を push
        res.push_back({a, ex});
    }
    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}
/* vector<pair<ll,ll>>で受け取る！
例えば360=2^3*3^2*5は
{{2,3},{3,2},{5,1}}*/

int main() {
    ll n;
    cin >> n;
    
    vector<pair<ll,ll>> a;
    a=prime_factorize(n);
    ll ans=0;
    for(int i = 0; i < a.size(); i++) {
        int x=a.at(i).second;
        for(int j = 1; j < 41; j++) {
            if(x-j>=0) {
                x -= j;
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}