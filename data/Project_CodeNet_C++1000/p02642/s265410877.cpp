#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

#define MAX 1000001
int A[MAX];
int ans[MAX];

void mark(int x) {
    if (A[x] >= 2) ans[x] = 0;
    for (int i = 2; i <= MAX / x; i++) {
        if (A[x*i]) ans[x*i] = 0;
    }
}

void solve() {
    int n;
    cin >> n;
    rep(i, n) {
        int a;
        cin >> a;
        A[a]++;
        ans[a] = 1;
    }

    vector<int> cand;
    rep(i, MAX) {
        if (ans[i]) {
            cand.push_back(i);
        }
    }

    rep(i, cand.size()) {
        mark(cand[i]);
    }


    int cnt = 0;
    rep(i, MAX) {
        if (ans[i]) cnt++;
    }

    cout << cnt << endl;
}

int main() {
    solve();
    return 0;
}
