#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;
    vector<int> ans(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        ans[a]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}