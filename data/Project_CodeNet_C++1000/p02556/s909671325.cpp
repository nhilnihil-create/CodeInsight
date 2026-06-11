#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;

const int MOD = 1e9+7;
const ll INF = 1e16;

int main() {
    FASTIO

    int n;
    cin >> n;
    vector<pair<ll,ll>> p(n);
    for(auto& q : p) {
        cin >> q.first >> q.second;
    }
    ll maxDist = -INF;
    ll x1 = -INF, y1 = -INF, x2 = INF, y2 = INF;
    for(auto q : p) {
        if(q.first + q.second > x1 + y1) {
            x1 = q.first, y1 = q.second;
        }
        if(q.first + q.second < x2 + y2) {
            x2 = q.first, y2 = q.second;
        }
    }
    maxDist = max(maxDist, abs(x1-x2)+abs(y1-y2));
    
    x1 = -INF, y1 = INF, x2 = INF, y2 = -INF;
    for(auto q : p) {
        if(q.first - q.second > x1 - y1) {
            x1 = q.first, y1 = q.second;
        }
        if(q.first - q.second < x2 - y2) {
            x2 = q.first, y2 = q.second;
        }
    }
    maxDist = max(maxDist, abs(x1-x2)+abs(y1-y2));
    
    cout << maxDist << "\n";
    
    return 0;
}