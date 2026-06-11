#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);


ll modnum = 1e9+7;

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main() {
    ll n; cin >> n;
    auto d1 = divisor(n);
    auto d2 = divisor(n-1);

    ll ans = d2.size()-1;
    for(auto k : d1) {
        if(k == 1) continue;
        ll tmpn = n;
        while(tmpn % k == 0) {
            tmpn /= k;
        }
        if(tmpn % k == 1) ans++;
    }

    cout << ans << endl;

    return 0;
}

