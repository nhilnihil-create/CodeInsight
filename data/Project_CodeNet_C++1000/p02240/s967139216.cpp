#include <bits/stdc++.h>

using namespace std;

#define Vi vector<int>
#define FOR(i,s,e) for (int i=s; i<e; i++)
#define ITER(v) v.begin(), v.end()

constexpr int N_MAX = 100'000;

Vi adj[N_MAX];
int color[N_MAX];

int n;
void build_color() {
    bool isqueued[N_MAX] = {false};
    for (int i = 0, c = 0; i < n; ++i) {
        if (isqueued[i]) { continue; }
        queue<int> q;
        q.push(i);
        isqueued[i] = true;
        while (!q.empty()) {
            const int j = q.front();
            color[j] = c;
            for (const int k : adj[j]) {
                if (isqueued[k]) { continue; }
                q.push(k);
                isqueued[k] = true;
            }
            q.pop();
        }
        ++c;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m;
    cin >> n >> m;

    int a, b;
    FOR(i,0,m) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    /*
    cout << "adj read." << endl;
    FOR(i,0,n) {
        for (const int j : adj[i]) {
            cout << " " << j;
        }
        cout << endl;
    }
    */
    build_color();

    int q;
    cin >> q;
    FOR(i,0,q) {
        cin >> a >> b;
        cout << (color[a] == color[b] ? "yes" : "no") << endl;
    }

    return 0;
}