#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 1000000;

int n, m, q;
int a[55], b[55], c[55], d[55];
int res = 0;
void dfs(vector<int> &A) {
    if (A.size() == n) {
        int tmp = 0;
        for (int i = 0; i < q; i++) {
            if (A[b[i]]-A[a[i]] == c[i]) tmp += d[i];
        }
        res = max(res, tmp);
        return;
    }
    int s;
    if (A.size() == 0) s = 1;
    else s = A[A.size()-1];
    for (int v = s; v <= m; v++) {
        A.push_back(v);
        dfs(A);
        A.pop_back();
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--;
    }
    vector<int>A;
    dfs(A);
    cout << res << endl;
    return 0;
}
