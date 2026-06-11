#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using int64 = long long;

int n, m, q, ans = 0;
vector<int> a, b, c, d;

void dfs(vector<int> A, int pre) {
    if (A.size() == n) {
        int sum = 0;
        for (int i=0; i<q; i++)
            if (A[b[i]]-A[a[i]]==c[i]) sum+=d[i];
        ans = max(ans, sum);
        return;
    }

    for (int i=pre; i<=m; i++) {
        A.push_back(i);
        dfs(A, i);
        A.pop_back();
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i=0; i<q; i++) {
        int aa, bb, cc, dd;
        cin >> aa >> bb >> cc >> dd;
        aa--; bb--;
        a.push_back(aa);
        b.push_back(bb);
        c.push_back(cc);
        d.push_back(dd);
    }

    dfs(vector<int>(), 1);

    cout << ans << endl;
}
