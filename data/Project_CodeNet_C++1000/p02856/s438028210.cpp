//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int m;
    cin >> m;
    ll ans = 0LL;
    ll sum = 0LL;
    rep(i, m) {
        int d;
        ll c;
        cin >> d >> c;
        sum += d * c;
        ans += c;
    }
    --ans;

    ans += sum/9LL;
    if(!(sum%9LL)) {
        ans--;
    }

    cout << ans << endl;
}