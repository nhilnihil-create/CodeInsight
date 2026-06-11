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
const int MAX = 1e5;

//mod(1e9+7)
const int mod = 1e9+7;
struct mint {
    ll x;
    mint(ll x = 0) : x(x % mod){}
    mint &operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint &operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
};

vector<mint> dp(13);

int main() {
    string s; cin >> s;
    int n = s.size();
    vint mo(n);
    mo[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        mo[i] = (mo[i+1]*10)%13;
    }
    dp[0] = 1;
    for (int i = n-1; i >= 0; i--) {
        vector<mint> next_dp(13,0);
        if (s[i] != '?') {
            int x = (s[i] - '0') * mo[i] % 13;
            rep(j,13) next_dp[(j+x)%13] += dp[j];
        }
        else {
            rep(j,13) {
                rep(k,10) {
                    int x = k*mo[i]%13;
                    next_dp[(j+x)%13] += dp[j];
                }
            }
        }
        swap(dp,next_dp);
    }
    cout << dp[5].x << endl;
}