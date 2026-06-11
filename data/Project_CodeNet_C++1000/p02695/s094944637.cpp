#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> a, b, c, d;
    for (int i = 0; i < Q; i++) {
        int ai, bi, ci, di;
        cin >> ai >> bi >> ci >> di;
        a.push_back(ai);
        b.push_back(bi);
        c.push_back(ci);
        d.push_back(di);
    }
    vector<int> perm(N+M-1, 1);
    for (int i = 0; i < N; i++) perm[i] = 0;
    long long ans = 0;
    do {
        vector<int> A(N+1, 0);
        int v = 1, cnt = 1;
        for (int j = 0; j < N + M -1; j++) {
            if (perm[j] == 1) {
                v++;
                continue;
            }
            A[cnt] = v;
            cnt++;
        }
        long long ans_temp = 0;
        bool ok = true;
        for (int i = 1; i <= N; i++) if (A[i-1] > A[i]) {
            ok = false;
            break;
        }
        if (ok) for (int i = 0; i < Q; i++) {
            if (A[b[i]] - A[a[i]] == c[i]) ans_temp += d[i];
        }
        if (ok) ans = max(ans, ans_temp);
        // for (auto i: perm) {
        //     cout << i;
        // }
        // cout << endl;
    } while(next_permutation(perm.begin(), perm.end()));
    cout << ans << endl;
    return 0;
}