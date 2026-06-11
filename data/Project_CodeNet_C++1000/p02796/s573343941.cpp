#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
        #include "debug.h"
        #define input freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        #else
        #define debug(...) 4
        #define input ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif

using ll = long long;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int main() {
    input;
        
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    set<pair<int, int>> s;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x - y, x + y});
        s.insert({x - y, x + y});
    }
    sort(v.begin(), v.end(), [](auto x, auto y) {
        return x.second < y.second;
    });
    // debug(v);
    int last = -INT_MAX;
    int cnt = 0;
    for (auto p : v) {
        if (last <= p.first) {
            cnt++;
            last = p.second;
        }
    }
    cout << cnt;
    

}   