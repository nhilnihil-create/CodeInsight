#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)

typedef pair<int, int> P;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n,p; cin >> n >> p;
    string s; cin >> s;

    reverse(s.begin(), s.end());


    // 10と素でない素数
    ll ans = 0;
    if(p == 2 || p == 5) {
        rep(i, n) {
            int now = s[i]-'0';
            if(now%p == 0) ans += n-i;
        }
        cout << ans << endl;
        return 0;
    }

    vector<int> sum(n+1, 0);
    int ten = 1;
    rep(i, n) {
        int now = (s[i]-'0') * ten % p;
        sum[i+1] = (sum[i] + now) % p;
        ten *= 10; ten %= p;
    }

    vector<int> cnt(p);
    ans = 0;
    rep(i, n+1) {
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    
    cout << ans << endl;

    return 0;
}