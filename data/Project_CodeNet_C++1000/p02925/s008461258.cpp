#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n-1));
    rep(i, n) {
        rep(j, n-1) {
            cin >> A[i][j];
            A[i][j]--;
        }
        reverse(A[i].begin(), A[i].end());
    }
    vector<P> p;
    auto check = [&](int i) {
        if (!A[i].size()) return;
        int j = A[i].back();
        if (A[j].back()==i) {
            if (i > j) swap(i, j);
            p.push_back(make_pair(i, j));
        }
    };
    rep(i, n) check(i);
    int day = 0;
    while(!p.empty()) {
        day++;
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
        vector<P> q;
        swap(p, q);
        for (P m : q) {
            A[m.first].pop_back();
            A[m.second].pop_back();
        }
        for (P m : q) {
            check(m.first);
            check(m.second);
        }
    }
    bool flg = true;
    rep(i, n) {
        if (A[i].size()) {
            flg = false;
        }
    }
    if (flg) cout << day << endl;
    else cout << -1 << endl;
    return 0;
}
