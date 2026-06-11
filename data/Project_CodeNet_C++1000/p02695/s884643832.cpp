#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dfs(int n, int m, int q, vector<int> a, vector<int> b, vector<int> c, vector<int> d, vector<int> A) {
    int sum = 0;
    if(A.size() == n + 1) {
        for(int i = 0; i < q; ++i) {
            if(A[b[i]] - A[a[i]] == c[i]) sum += d[i];
        }
        return sum;
    }

    A.emplace_back(A.back());
    while(A.back() <= m) {
        sum = max(sum, dfs(n, m, q, a, b, c, d, A));
        A.back()++;
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(q), b(q), c(q), d(q);
    for(int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    printf("%d\n", dfs(n, m, q, a, b, c, d, vector<int>(1, 1)));

    return 0;
}