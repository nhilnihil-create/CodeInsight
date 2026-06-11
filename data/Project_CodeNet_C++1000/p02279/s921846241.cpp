#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

struct node {
    int p = -1;
    int d;
    vector<int> c;
};

void dfs(int s, vector<node> &v, vector<bool> &seen, int depth) {
    seen[s] = true;
    v[s].d = depth;
    rep(i, v[s].c.size()) {
        int next = v[s].c[i];
        if (seen[next])
            continue;
        dfs(next, v, seen, depth + 1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<node> v(N);
    int s = 0;
    rep(i, N) {
        int id, k;
        cin >> id >> k;
        rep(j, k) {
            int a;
            cin >> a;
            v[id].c.push_back(a);
            v[a].p = id;
        }
    }

    rep(i, N) {
        if (v[i].p == -1) {
            s = i;
            break;
        }
    }

    vector<bool> seen(N, false);
    int depth = 0;
    dfs(s, v, seen, depth);

    rep(i, N) {
        cout << "node"
             << " " << i << ":"
             << " ";
        cout << "parent = " << v[i].p << ","
             << " ";
        cout << "depth = " << v[i].d << ","
             << " ";
        if (i == s) {
            cout << "root, [";
            if (v[i].c.empty()) {
                cout << "]";
            } else {
                rep(j, v[i].c.size() - 1) { cout << v[i].c[j] << ", "; }
                cout << v[i].c.back() << "]";
            }

        } else if (v[i].c.size() == 0) {
            cout << "leaf, [";
            if (v[i].c.empty()) {
                cout << "]";
            } else {
                rep(j, v[i].c.size() - 1) { cout << v[i].c[j] << ", "; }
                cout << v[i].c.back() << "]";
            }
        } else {
            cout << "internal node, [";
            if (v[i].c.empty()) {
                cout << "]";
            } else {
                rep(j, v[i].c.size() - 1) { cout << v[i].c[j] << ", "; }
                cout << v[i].c.back() << "]";
            }
        }
        cout << endl;
    }
}
