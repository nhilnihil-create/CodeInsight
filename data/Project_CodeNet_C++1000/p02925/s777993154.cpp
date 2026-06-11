#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    deque<int> A[N];
    rep(i, N) {
        deque<int> a(N-1);
        rep(j, N-1) cin >> a[j];
        rep(k, N-1) a[k]--; 
        A[i] = a;
    }
    ll ans = 0;
    ll match = 0;
    while (match < N * (N-1) / 2) {
        ans++;
        bool flag = false;
        vector<bool> used(N);
        for (int i = 0; i < N; i++) {
            if (used[i] || A[i].empty()) continue;
            used[i] = true;
            int op = A[i].front();
            if (used[op]) continue;
            if (A[op].front() == i) {
                match++;
                used[op] = true;
                A[i].pop_front(); A[op].pop_front();
                flag = true;
            }
        }
        if (!flag) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}