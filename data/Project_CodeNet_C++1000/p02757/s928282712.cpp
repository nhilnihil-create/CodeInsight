#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, p;
    string s;
    cin >> n >> p >> s;
    if (p == 2) {
        ll ans = 0;
        rep(i, n) {
            int x = s[i] - '0';
            if (x % 2 == 0) {
                ans += i+1;
            }
        }
        cout << ans << endl;
    } else if (p == 5) {
        ll ans = 0;
        rep(i, n) {
            int x = s[i] - '0';
            if (x % 5 == 0) {
                ans += i+1;
            }
        }
        cout << ans << endl;
    } else {
        reverse(s.begin(), s.end());
        vi modsum(n+1, 0);
        int now = 1;
        rep(i, n) {
            modsum[i+1] = (modsum[i] + (s[i] - '0') * now) % p;
            now = (now * 10) % p;
        }
        map<int, int> mp;
        rep(i, n+1) mp[modsum[i]]++;
        ll ans = 0;
        for (auto&& p : mp) ans += (ll)p.se * (p.se - 1) / 2;
        cout << ans << endl;
    }
    
}