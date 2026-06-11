#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int N;

void calc_sum(int n, ll sum, vector<vector<int>> &tree, vector<ll> &cnt, vector<ll> &ans, vector<bool> &seen) {
    seen.at(n) = true;
    ans.at(n) = sum + cnt.at(n);
    for (auto x : tree.at(n)) {
        if (!seen.at(x)) calc_sum(x, ans.at(n), tree, cnt, ans, seen);
    }
}

int main() {
    int Q, a, b, p, x;
    cin >> N >> Q;
    vector<vector<int>> tree(N);
    vector<bool> seen(N);
    vector<ll> cnt(N), ans(N);
    rep(i,N-1) {
        cin >> a >> b;
        --a;
        --b;
        tree.at(a).push_back(b);
        tree.at(b).push_back(a);
    }
    rep(i,Q) {
        cin >> p >> x;
        --p;
        cnt.at(p) += x;
    }
    calc_sum(0, 0, tree, cnt, ans, seen);
    rep(i,N) cout << ans.at(i) << " ";
}
