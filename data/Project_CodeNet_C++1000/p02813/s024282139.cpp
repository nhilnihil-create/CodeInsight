#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];
    vector<int> perm(N);
    for (int i = 0; i < N; i++) perm[i] = i + 1;
    int n = 0;
    int a, b;
    do {
        if (perm == P) a = n;
        if (perm == Q) b = n;
        n++;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << abs(a - b) << endl;
}