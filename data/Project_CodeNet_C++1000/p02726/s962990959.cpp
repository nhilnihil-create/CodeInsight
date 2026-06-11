#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

typedef pair<int, int> P;

int N;
vector<vi> G;

vi dijkstra(int start) {
    vi d(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P{0, start});
    d[start] = 0;

    while (!pq.empty()) {
        P p = pq.top(); pq.pop();
        int x = p.second;
        if (p.first > d[x]) continue;

        for (int i = 0; i < G[x].size(); i++) {
            int j = G[x][i];
            if (d[j] > d[x] + 1) {
                d[j] = d[x] + 1;
                pq.push(P{d[x] + 1, j});
            }
        }
    }

    return d;
}

int main() {
    cin >> N;
    G.resize(N);
    int X, Y; cin >> X >> Y;
    X--; Y--;

    rep(i, N - 1) {
        G[i].push_back(i + 1);
        G[i + 1].push_back(i);
    }
    G[X].push_back(Y);
    G[Y].push_back(X);

    map<int, int> cnt;
    rep(i, N) {
        vi res = dijkstra(i);

        // rep(i, N) cout << res[i] << " "; cout << endl;

        for (int j = i + 1; j < N; j++) {
            cnt[res[j]]++;
        }
    }

    for (int i = 1; i < N; i++) {
        cout << cnt[i] << endl;
    }
}
