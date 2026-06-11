#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

typedef long long ll;

using namespace std;


int main() {
    ll H, W, M;
    cin >> H >> W >> M;
    vector<pair<ll, ll>> row(H);
    for (int i = 0; i < H; ++i) {
        row[i] = {0, i};
    }
    vector<pair<ll, ll>> col(W);
    for (int i = 0; i < W; ++i) {
        col[i] = {0, i};
    }
    set<pair<ll, ll>> s;
    for (int i = 0; i < M; ++i) {
        ll h, w;
        cin >> h >> w;
        --h; --w;
        s.insert({h, w});
        ++row[h].first;
        ++col[w].first;
    }

    sort(row.begin(), row.end(), greater<>());
    sort(col.begin(), col.end(), greater<>());

    for (auto it_r = row.begin(); it_r != row.end() && it_r->first == row[0].first; ++it_r) {
        for (auto it_c = col.begin(); it_c != col.end() && it_c->first == col[0].first; ++it_c) {
            if (s.find({it_r->second, it_c->second}) == s.end()) {
                cout << row[0].first + col[0].first << endl;
                return 0;
            }
        }
    }

    cout << row[0].first + col[0].first - 1 << endl;

    return 0;
}