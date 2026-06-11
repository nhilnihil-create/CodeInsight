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

int main() {
    string s; cin >> s;
    int n = s.size();
    vint mo(n);
    mo[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        mo[i] = (mo[i+1]*10)%13;
    }
    int sum = 0;
    int ct = 0;
    rep(i,n) {
        if (s[i] != '?') {
            sum += mo[i]*(s[i]-'0');
            sum %= 13;
            ct++;
        }
    }
    if (ct == n) {
        if (sum == 5) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    int x = 5-sum;
    if (x < 0) x += 13;
    vector<map<int,mint>> mp;
    rep(i,n) {
        if (s[i] == '?') {
            map<int,mint> tmp;
            rep(j,10) tmp[j*mo[i]%13] += 1;
            mp.push_back(tmp);
        }
    }
    map<int,mint> ans = mp[0];
    REP(i,mp.size()) {
        map<int,mint> tmp;
        rep(j,14)rep(k,14) {
            tmp[(j+k)%13] += ans[j] * mp[i][k];
        } 
        swap(ans,tmp); 
    }
    cout << ans[x].x << endl;
}