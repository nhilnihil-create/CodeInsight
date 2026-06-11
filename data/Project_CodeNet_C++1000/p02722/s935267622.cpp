#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 100005;

//素因数分解
vector<pair<ll,int>> factorize(ll n) {
    vector<pair<ll,int>> res;
    ll N = n;
    for (ll i = 2; i * i <= N; i++) {
        if (n % i != 0) continue;
        res.emplace_back(i,0);
        while (n % i == 0) {
            n /= i;
            res.back().second++;
        } 
    }
    if (n != 1) res.emplace_back(n,1);
    return res;
}

int main() {
    ll n; cin >> n;
    vector<pair<ll,int>> x = factorize(n-1);
    ll sum = 1;
    rep(i,x.size()) {
        sum *= x[i].second+1;
    }
    sum--;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            ll j = n/i;
            ll x = n;
            while (x % i == 0) {
                x /= i;
            }
            if (x % i == 1) sum++;
            x = n;
            if (i != j) {
                while (x % j == 0) {
                    x /= j;
                }
                if (x % j == 1) sum++;
            }
        }
    }
    sum++;
    cout << sum << endl;
}