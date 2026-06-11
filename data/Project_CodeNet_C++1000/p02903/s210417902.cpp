#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX=1001001;
const ll MOD=1000000007;
int main()
{
    ll h, w, a, b;
    cin >> h>>w>>a >> b;
    vector<vector<ll>>d(h, vector<ll>(w));
    rep(i, h) {
        rep(j, w) {
            if ((i>=b&&j>=a)||(i<b&&j<a)) {
                d[i][j]=1;
            }
        }
    }
    rep(i, h) {
        rep(j, w) {
            cout<<d[i][j];
        }
        cout<<endl;
    }
}