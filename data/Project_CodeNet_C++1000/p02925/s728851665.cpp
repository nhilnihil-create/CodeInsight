#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // candは前の日に試合をやった人
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int> (N-1));
    rep(i, N) rep(j, N-1) {
        cin >> A[i][j];
        --A[i][j];
    }
    rep(i, N) reverse(A[i].begin(), A[i].end());
    vector<P> cand;
    auto check = [&](int x) {
        if (A[x].empty()) return;
        int op = A[x].back();
        if (A[op].back() == x) {
            P p(x, op);
            if (p.second < p.first) swap(p.first, p.second);
            cand.push_back(p);
        }
    };
    rep(i, N) check(i);
    int ans = 0;
    while (!cand.empty()) {
        ans++;
        vector<P> prevCand;
        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());
        swap(cand, prevCand);
        for (auto p : prevCand) {
            int a = p.first, b = p.second;
            A[a].pop_back(); A[b].pop_back();
            check(a); check(b);            
        }
    }
    rep(i, N) {
        if (!A[i].empty()) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}

// 15