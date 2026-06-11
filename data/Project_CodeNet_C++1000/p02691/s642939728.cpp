#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> r(n, 0), l(n, 0);
    for (int i = 0; i < n; ++i) {
        int left = i - a[i];
        int right = i + a[i];
        if (left >= 0) l[left]++;
        if (right < n) r[right]++;
    }

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += (ll)r[i] * (ll)l[i];
    }
    cout << res << endl;
}