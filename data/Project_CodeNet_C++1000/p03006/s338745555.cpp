#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > X(n);
    rep(i, n) {
        cin >> X[i].first >> X[i].second;
    }

    map<pair<int, int>, int> con;
    rep(i, n) {
        rep(j, n) {
            if(i == j) continue;
            int x, y;
            x = X[i].first - X[j].first;
            y = X[i].second - X[j].second;
            pair<int, int> k = make_pair(x, y);
            con[k]++;
        }
    }

    int ma=0;
    for(auto i:con) {
        ma = max(ma, i.second);
    }

    cout << n-ma << endl;
}