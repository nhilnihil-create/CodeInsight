#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)

void chmax(ll& a, ll b) { a = max(a, b); }
void chmin(ll& a, ll b) { a = min(a, b); }

using P = pair<int, int>;

int main() {
    int n,t; cin >> n >> t;
    vector<P> ba;
    rep(i, n) {
        int a,b;
        cin >> a >> b;
        ba.push_back(make_pair(b,a));
    }
    //sort(ba.rbegin(), ba.rend());
    vector<vector<int>> dp1(n+1, vector<int>(t, 0));
    vector<vector<int>> dp2(n+1, vector<int>(t, 0));

    vector<int> ans1(n,0);
    vector<int> ans2(n,0);
    rep(i, n) {
        rep(j, t) {
            if(j >= ba[i].second) {
                if(i > 0) dp1[i][j] = max(dp1[i-1][j-ba[i].second] + ba[i].first, dp1[i-1][j]);
                else dp1[i][j] = ba[i].first;
            } else {
                if(i > 0) dp1[i][j] = dp1[i-1][j];
            }
            ans1[i] = max(ans1[i], dp1[i][j]);
        }
    }

    for(int i=n-1; i >= 0; i--) {
        rep(j, t) {
            if(j >= ba[i].second) {
                dp2[i][j] = max(dp2[i+1][j-ba[i].second] + ba[i].first, dp2[i+1][j]);
            } else {
                dp2[i][j] = dp2[i+1][j];
            }
            ans2[i] = max(ans2[i], dp2[i][j]);
        }
    }

    int ans = 0;
    rep(i, n) {
        int tmpans = 0;
        rep(j, t) {
            if(i == 0) {
                tmpans = max(tmpans, dp2[i + 1][j]);
            } else if(i == n-1) {
                tmpans = max(tmpans, dp1[i - 1][j]);
            } else {
                tmpans = max(tmpans, dp1[i - 1][j] + dp2[i + 1][t - 1 - j]);
            }
        }
        ans = max(ans, tmpans+ba[i].first);
    }

    cout << ans << endl;
    return 0;
}


/**
3 1000
2 40
500 20
500 12


5 900
200 1
100 2
1000 3
900 4
900 5
**/