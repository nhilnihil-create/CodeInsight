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

void print(int i, int p, int d, int type, vi &ch) {
    cout << "node " << i << ": parent = " << p << ", depth = " << d << ", ";
    if(type == 0) {
        cout << "root, ";
    } else if(type == 1) {
        cout << "internal node, ";
    } else {
        cout << "leaf, ";
    }
    cout << '[';
    rep(i, ch.size()) {
        if(i) cout << ", ";
        cout << ch[i];
    }
    cout << "]\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi dep(n);
    vvi ch(n);
    int root = -1;
    vi che(n);
    rep(i, n) {
        int j;
        cin >> j;
        if(!i) root = j;
        int k;
        cin >> k;
        ch[j].resize(k);
        rep(i, k) {
            cin >> ch[j][i];
            che[ch[j][i]]++;
        }
    }
    rep(i, n) {
        if(!che[i]) root = i;
    }
    vi type(n);
    vi par(n);
    function<void(int, int)> dfs = [&](int i, int j) {
        par[i] = j;
        for(int ne:ch[i]) {
            if(ne == j) continue;
            dep[ne] = dep[i]+1;
            if(ch[ne].size() == 0) {
                type[ne] = 100;
            } else {
                type[ne] = 1;
            }
            dfs(ne, i);
        }
    };
    dfs(root, -1);
    rep(i, n) {
        print(i, par[i], dep[i], type[i], ch[i]);
    }
}
