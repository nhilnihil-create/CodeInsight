#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> s(H);
    rep(i, H) cin >> s[i];

    deque<P> que;
    que.push_front({0, 0});
    ll dy[2] = {0, 1};
    ll dx[2] = {1, 0};

    vector<vector<ll>> dist(H, vector<ll>(W, INF));
    if (s[0][0] == '.')
        dist[0][0] = 0;
    else
        dist[0][0] = 1;
    while (que.size()) {
        P now = que.front();
        que.pop_front();

        if (s[now.fi][now.se] == '.') {
            rep(i, 2) {
                ll ny = now.fi + dy[i], nx = now.se + dx[i];
                if (H <= ny || W <= nx) continue;
                if (s[ny][nx] == '#') {
                    if (dist[ny][nx] > dist[now.fi][now.se] + 1) {
                        dist[ny][nx] = dist[now.fi][now.se] + 1;
                        que.push_back({ny, nx});
                    }
                } else {
                    if (dist[ny][nx] > dist[now.fi][now.se]) {
                        dist[ny][nx] = dist[now.fi][now.se];
                        que.push_front({ny, nx});
                    }
                }
            }
        } else {
            rep(i, 2) {
                ll ny = now.fi + dy[i], nx = now.se + dx[i];
                if (H <= ny || W <= nx) continue;
                if (s[ny][nx] == '#') {
                    if (dist[ny][nx] > dist[now.fi][now.se]) {
                        dist[ny][nx] = dist[now.fi][now.se];
                        que.push_back({ny, nx});
                    }

                } else {
                    if (dist[ny][nx] > dist[now.fi][now.se]) {
                        dist[ny][nx] = dist[now.fi][now.se];
                        que.push_front({ny, nx});
                    }
                }
            }
        }
        /*rep(i, H) {
            rep(j, W) {
                if (dist[i][j] != INF)
                    cout << dist[i][j] << " ";
                else
                    cout << -1 << " ";
            }

            cout << "\n";
        }
        cout << "\n";*/
    }

    cout << dist[H - 1][W - 1] << "\n";
    return 0;
}