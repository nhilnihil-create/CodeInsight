#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

vector<long long> enum_div(long long n) {
    vector<long long> res;
    for (long long i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i*i != n) {
                res.push_back(n/i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;

    auto d1 = enum_div(n-1);
    auto d2 = enum_div(n);

    int ans = d1.size() - 1;
    for (auto x : d2) {
        if (x == 1) continue;
        ll m = n;
        while (m%x == 0) {
            m /= x;
        }
        if (m % x == 1) ans++;
    }
    cout << ans << endl;
    
}