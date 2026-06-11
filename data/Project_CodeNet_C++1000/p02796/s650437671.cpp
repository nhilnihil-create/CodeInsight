#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    vector<LP> v(n);
    rep(i, n) {
        ll x, l;
        cin >> x >> l;
        v[i].first = x - l;
        v[i].second = x + l;
    }

    sort(ALL(v), [](LP a, LP b){return a.second < b.second;});
    ll ans = 0;
    ll value = v[0].second;
    ans++;
    rrep(i, n - 1) {
        if(v[i].first < value) continue;
        else {
            value = v[i].second;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}