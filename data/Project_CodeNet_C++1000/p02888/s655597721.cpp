#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];
    sort(l.begin(), l.end());
    int ans = 0;
    for (int i = 2; i < n; i++) {
        for (int k = 1; k < i; k++) {
            int diff = l[i] - l[k];
            if (l[k-1] <= diff)
                continue;
            int idx = upper_bound(l.begin(), l.end(), diff) - l.begin();
            ans += k - idx;
        }
    }
    cout << ans;
    return 0;
}