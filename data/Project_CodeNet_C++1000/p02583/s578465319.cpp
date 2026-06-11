#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    int N; cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];

    int cnt = 0;
    for (int i = 0; i < N-2; i++) {
        for (int j = i + 1; j < N-1; j++) {
            for (int k = j + 1; k < N; k++) {
                if (L[i] != L[j] && L[j] != L[k] && L[k] != L[i]) {
                    if (max(L[i], L[j]) >= min(L[i], L[j]) + L[k]) continue;
                    if (L[k] >= L[i] + L[j]) continue;
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}
