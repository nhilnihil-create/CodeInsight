#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P, Q;
    int P_num = 0, Q_num = 0;
    for (int i = 0; i < N; i++) {
        int p;cin >> p;
        P.push_back(p);
        P_num = P_num * 10 + p;
    }
    for (int i = 0; i < N; i++) {
        int q;cin >> q;
        Q.push_back(q);
        Q_num = Q_num * 10 + q;
    }
    int cnt = 0;
    if (P_num < Q_num) do{
        bool ok = true;
        for (int i = 0; i < N; i++) if (P[i] != Q[i]) {
           ok = false;
           break;
        }
        if (ok) break;
        cnt++;
    } while (next_permutation(P.begin(), P.end()));
    else do{
        bool ok = true;
        for (int i = 0; i < N; i++) if (P[i] != Q[i]) {
           ok = false;
           break;
        }
        if (ok) break;
        cnt++;
    } while (next_permutation(Q.begin(), Q.end()));
    cout << cnt << endl;
    return 0;
}