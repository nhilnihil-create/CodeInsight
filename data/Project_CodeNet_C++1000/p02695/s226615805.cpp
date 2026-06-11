#include <bits/stdc++.h>
using namespace std;
vector<int> a, b, c, d;
int N, M, Q;
int ans = 0;
void dfs(vector<int>A){
    if (A.size() == N + 1) {
        int now = 0;
        for (int i = 0; i < Q; i++) {
            if (A[b[i]] - A[a[i]]  == c[i]) {
                now += d[i];
            }
        }
        ans = max(now, ans);
        return;
    }
    A.push_back(A.back());
    while (A.back() <= M) {
        dfs(A);
        A.back()++;
    }
}
int main() {
    cin >> N >> M >> Q;
    a = b = c = d = vector<int>(Q);
    for (int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    dfs(vector<int>(1,1));
    cout << ans << endl;

}
