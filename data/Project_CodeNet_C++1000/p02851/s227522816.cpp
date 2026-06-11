//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

int mod;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> mod;
    vector<int> a(n), sum(n+1);
    rep(i, n) {
        cin >> a[i];
        sum[i+1] = sum[i] + a[i] - 1;
        sum[i+1] %= mod;
    }

    //rep(i, n) cout << sum[i+1] << (i == n-1?'\n':' ');

    unordered_map<int, int> mp;
    ll ans = 0;
    vector<int> check(n);
    rep(i, n) {
        check[i] = sum[i];
        mp[sum[i]]++;
        if(i >= mod-1) {
            mp[check[i-mod+1]]--;
        }
        ans += mp[sum[i+1]];
    }

    cout << ans << endl;
}