#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int a[100], b[100], c[100], d[100];
long long ans = 0;

void dfs(vector<int> &A) {
    if (A.size() == n) {
        long long now = 0;
        for (int i = 0; i < q; ++i) {
            if ((A[b[i]] - A[a[i]]) == c[i]) now += d[i];
        }
        ans = max(ans, now);
        return;
    }

    int t = A.back();
    for (int i = t; i <= m; ++i) {
        A.push_back(i);
        dfs(A);
        A.pop_back();
    }

}

int main(void) {
    cin >> n >> m >> q;
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }
    vector<int> v(1, 1);
    dfs(v);
    cout << ans << endl;
}