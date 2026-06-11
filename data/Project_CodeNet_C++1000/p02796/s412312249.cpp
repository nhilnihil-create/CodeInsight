#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<map>
#include<deque>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define erep(i, n) for (int i = 0; i <= (int)(n); i++)
using p = pair<ll, ll>;

int main() {
    int n; cin >> n;
    vector<p> arms(n);
    rep (i, n) {
        ll x, l;
        cin >> x >> l;
        arms[i].first = x + l;
        arms[i].second = x - l;
    }
    sort(arms.begin(), arms.end());

    ll ans = 0;
    ll tgt = -(1LL<<60);
    rep (i, n) {
        if (arms[i].second < tgt) continue;
        ans++;
        tgt = arms[i].first;
    }
    cout << ans << endl;
    
}
