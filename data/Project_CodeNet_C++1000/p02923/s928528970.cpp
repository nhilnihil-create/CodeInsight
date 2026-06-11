#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    int count = 0;
    int ans = 0;
    rep(i,n) cin >> h[i];

    for (int i = 1; i < n; i++) {
        if (h[i] > h[i-1]) {
            ans = max(ans, count);
            count = 0;
        }
        else {
            count++;
        }
        
    }

    ans = max(ans, count);

    cout << ans << endl;

    return 0;
}