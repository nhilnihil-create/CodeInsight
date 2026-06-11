#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, sum = 0;
    cin >> N;
    vector<int> A(N);
    vector<pair<int, int>> ans;
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    sort(A.begin(), A.end());
    
    if (A[0] <= 0) {
        vector<bool> use(N, false);
        int now = A[0];
        for (int i = 1; i < N-1; i++) if (A[i] >= 0) {
            ans.emplace_back(now, A[i]);
            now -= A[i];
            use[i] = true;
        }
        A[0] = now;
        sum = A[N-1];
        for (int i = 0; i < N-1; i++) if (!use[i]) {
            ans.emplace_back(sum, A[i]);
            sum -= A[i];
        }
    } else {
        sum = A[0];
        for (int i = 1; i < N-1; i++) {
            ans.emplace_back(sum, A[i]);
            sum -= A[i];
        }
        ans.emplace_back(A[N-1], sum);
        sum = A[N-1] - sum;
    }
    
    printf("%d\n", sum);
    for (auto e : ans) printf("%d %d\n", e.first, e.second);
    return 0;
}