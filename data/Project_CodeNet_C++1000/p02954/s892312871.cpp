#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;  cin >> S;
    int N = S.size();
    vector<int> f(N), f_cp(N);
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'R') f[i] = f_cp[i] = i + 1;
        else f[i] = f_cp[i] = i - 1;
    }

    int K = 1e5;
    vector<int> now(N), now_cp(N);
    for (int i = 0; i < N; ++i) now[i] = now_cp[i] = i;
    while (K) {
        if (K & 1) {
            for (int i = 0; i < N; ++i) now[i] = f[now_cp[i]];
            now_cp = now;
        }
        for (int i = 0; i < N; ++i) f[i] = f_cp[f_cp[i]];
        f_cp = f;
        K >>= 1;
    }

    vector<int> ans(N);
    for (int i = 0; i < N; ++i) ++ans[now[i]];
    for (int i = 0; i < N; ++i) cout << ans[i] << " ";
    cout << endl;
}
