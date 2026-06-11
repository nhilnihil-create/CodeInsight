#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        sort(all(s));
        mp[s]++;
    }
    ll res = 0;
    for (auto v : mp) {
        res += (ll)v.second * (ll)(v.second - 1) / 2;
    }
    cout << res << endl;
}