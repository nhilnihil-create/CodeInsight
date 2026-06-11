#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair < ll, ll > PLL;
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    if ( n <= 2 ) {
        cout << 1 << endl;
        return 0;
    }
    vector<pair<ll, ll>> xy(n);
    vector<ll> xdif(n-1);
    vector<ll> ydif(n-1);
    rep(i, n) {
        ll tmp_x, tmp_y;
        cin >> tmp_x >> tmp_y;
        xy[i] = make_pair(tmp_x, tmp_y);
    }
    sort(xy.begin(), xy.end());
    rep(i ,n ) {
        if ( i == 1 ) {
            xdif[0] += xy[1].first - xy[0].first;
            ydif[0] += xy[1].second - xy[0].second;
        }
        else if ( i > 1 ) {
            xdif[i-1] += xy[i].first - xy[i-1].first + xdif[i-2];
            ydif[i-1] += xy[i].second - xy[i-1].second + ydif[i-2];
        }
    }
    map<pair<ll, ll>, int> mp;
    rep(i, n-1) {
        for ( int j = i; j < n - 1; ++j ) {
            if ( i == 0 ) {
//                cout << xdif[j] << " " << ydif[j] << endl;
                ++mp[make_pair(xdif[j], ydif[j])];
            }
            if ( i >= 1 ) {
//                cout << xdif[j] - xdif[i-1] << " " << ydif[j] - ydif[i-1] << endl;
                ++mp[make_pair(xdif[j] - xdif[i-1], ydif[j] - ydif[i-1])];
            }
        }
    }
    int max_num = 0;
    for ( auto tmp_mp : mp ) {
//        cout << tmp_mp.second << endl;
        max_num = max(max_num, tmp_mp.second);
    }
    cout << n - max_num << endl;
    return 0;
}
