//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vvi G(3*n);
    auto add = [&](int i, int j) {
        G[i*3].push_back(j*3+1);
        G[i*3+1].push_back(j*3+2);
        G[i*3+2].push_back(j*3);
    };
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        add(u, v);
    }

    int s, t;
    cin >> s >> t;
    s--; t--;

    vi dist(3*n, -1);
    dist[s*3] = 0;
    queue<int> q;
    q.push(s*3);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int ne:G[now]) {
            if(dist[ne] != -1) continue;
            dist[ne] = dist[now] + 1;
            q.push(ne);
            if(ne == t*3) {
                while(!q.empty()) {
                    q.pop();
                }
                break;
            }
        }
    }
    if(dist[3*t] > 0) {
        dist[3*t] /= 3;
    }
    cout << dist[3*t] << endl;
}