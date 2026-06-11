#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll H, W;
vector<string> maze;
ll w_dist[2010][2010];
ll h_dist[2010][2010];

int main() {
    cin >> H >> W;
    maze.resize(H);
    rep(i, H) cin >> maze[i];

    // w_dist の構築
    rep(i, H) {
        ll tmp = 0;
        // vector<ll> v;
        vector<pair<char, int>> v;
        for (int j = 0; j < W; j++) {
            if (maze[i][j] == '#') {
                v.push_back(make_pair('#', 1));
                continue;
            }

            // .
            if (v.size() == 0) {
                v.push_back(make_pair('.', 1));
                continue;
            } 

            int last = v.size() - 1;
            pair<char, int> p = v[last];
            if (p.first == '#') {
                v.push_back(make_pair('.', 1));
            } else {
                p.second++;
                v[last] = p;
            }
        }

        // 更新
        int start = 0;
        for (int j = 0; j < v.size(); j++) {
            // cout << v[j].first << " " << v[j].second << endl;
            for (int k = 0; k < v[j].second; k++) {
                if (v[j].first == '#') {
                    w_dist[i][k + start] = 0;
                } else {
                    w_dist[i][k + start] = v[j].second;
                }
            }
            start += v[j].second;
        }
    }

    // rep(i, H) {
    //     rep(j, W) {
    //         cout << w_dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // h_dist の構築
    rep(j, W) {
        ll tmp = 0;
        // vector<ll> v;
        vector<pair<char, int>> v;
        for (int i = 0; i < H; i++) {
            if (maze[i][j] == '#') {
                v.push_back(make_pair('#', 1));
                continue;
            }

            // .
            if (v.size() == 0) {
                v.push_back(make_pair('.', 1));
                continue;
            } 

            int last = v.size() - 1;
            pair<char, int> p = v[last];
            if (p.first == '#') {
                v.push_back(make_pair('.', 1));
            } else {
                p.second++;
                v[last] = p;
            }
        }

        // rep(j, v.size()) {
        //     cout << v[j].first << " " << v[j].second << endl;
        // }

        // 更新
        int start = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int k = 0; k < v[i].second; k++) {
                if (v[i].first == '#') {
                    h_dist[k + start][j] = 0;
                } else {
                    h_dist[k + start][j] = v[i].second;
                }
            }
            start += v[i].second;
        }
    }
    // rep(i, H) {
    //     rep(j, W) {
    //         cout << h_dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = 0;
    rep(i, H)rep(j, W) {
        if (maze[i][j] == '#') continue;

        ll c = h_dist[i][j] + w_dist[i][j] - 1;
        ans = max(ans, c);
    }
    cout << ans << endl;
}