#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);

int main() {
    int n;
    cin >> n;
    vector<pair<ll,ll>> p(n);
    rep(i,n) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p.begin(), p.end());
    ll now = 0;
    rep(i,n) {
        now += p[i].second;
        if (now > p[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}