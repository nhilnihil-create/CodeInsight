#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, vector<int> b, int N) {
    for (int i = 0; i < N; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    int N; cin >> N;
    vector<int> P(N), Q(N), perm(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];
    for (int i = 0; i < N; i++) perm[i] = i + 1;
    int p_idx = -1, q_idx = -1;
    int counter = 0;
    do {
        counter++;
        if (p_idx == -1) {
            if (check(P, perm, N)) {
                p_idx = counter;
            }
        }
        if (q_idx == -1) {
            if (check(Q, perm, N)) {
                q_idx = counter;
            }
        }
    } while (next_permutation(perm.begin(), perm.end()) && (p_idx == -1 || q_idx == -1));
    cout << abs(p_idx - q_idx);
}