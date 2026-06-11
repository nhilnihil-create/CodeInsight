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
    int l;
    int r;
};

int N;
vector<node> G;

void rec1(int s, vector<int> &pre) {
    if (s == -1)
        return;
    pre.push_back(s);
    if (G[s].l != -1)
        rec1(G[s].l, pre);
    if (G[s].r != -1)
        rec1(G[s].r, pre);
}

void rec2(int s, vector<int> &in) {
    if (s == -1)
        return;
    rec2(G[s].l, in);
    in.push_back(s);
    rec2(G[s].r, in);
}

void rec3(int s, vector<int> &post) {
    if (s == -1)
        return;
    rec3(G[s].l, post);
    rec3(G[s].r, post);
    post.push_back(s);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    G.resize(N);
    rep(i, N) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].l = b, G[a].r = c;
        if (b != -1)
            G[b].p = a;
        if (c != -1)
            G[c].p = c;
    }

    int s;

    rep(i, N) {
        if (G[i].p == -1) {
            s = i;
            break;
        }
    }

    vector<int> pre, in, post;
    rec1(s, pre);
    rec2(s, in);
    rec3(s, post);

    cout << "Preorder" << endl;
    cout << " ";
    rep(i, N) {
        cout << pre[i];
        if (i != N - 1)
            cout << " ";
    }
    cout << endl;

    cout << "Inorder" << endl;
    cout << " ";
    rep(i, N) {
        cout << in[i];
        if (i != N - 1)
            cout << " ";
    }
    cout << endl;

    cout << "Postorder" << endl;
    cout << " ";
    rep(i, N) {
        cout << post[i];
        if (i != N - 1)
            cout << " ";
    }
    cout << endl;
}
