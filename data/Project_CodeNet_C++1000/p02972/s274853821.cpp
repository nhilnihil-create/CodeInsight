#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> putted(n+10, 0);
    for (int i = n; i >= 1; i--) {
        int sum_temp = 0;
        for (int j = i + i; j <= n; j += i) sum_temp += putted[j];
        putted[i] = (a[i] + sum_temp) % 2;
    }
    int m = count(putted.begin(), putted.end(), 1);
    if (m == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> ans;
    cout << m << endl;
    for (int i = 1; i <= n; i++) if (putted[i]) ans.push_back(i);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) cout << ' ';
    }
    cout << endl;
    return 0;
}