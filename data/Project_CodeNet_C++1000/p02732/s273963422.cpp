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
    vector<int> a(n);
    map<int, ll> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }

    ll res = 0;
    for (auto &x : mp){
        res += x.second * (x.second - 1) / 2;
    }

    ll x;
    for (int i = 0; i < n; ++i) {
        x = res - mp[a[i]] * (mp[a[i]] - 1) / 2;
        x += (mp[a[i]] > 1) ? (mp[a[i]] - 1) * (mp[a[i]] - 2) / 2 : 0;
        cout << x << endl;
    }
}