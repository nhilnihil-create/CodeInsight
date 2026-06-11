#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;
const ll MOD = 1e9 + 7;


// 素因数分解(first要素がfactで、second要素がその個数)
vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}


int main(){
    ll n;
    cin >> n;

    auto v = prime_factorize(n);
    int ans = 0;
    for(auto p: v){
        int c = 1;
        while(p.second-c >= 0){
            p.second -= c;
            c++;
            ans++;
        }
    }

    cout << ans << endl;
}