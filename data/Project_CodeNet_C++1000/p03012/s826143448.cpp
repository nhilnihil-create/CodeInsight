#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    int sum = 0;
    rep(i, 0, n) {
        cin >> w[i];
        sum += w[i];
    }

    vector<int> s(n + 1, 0);
    rep(i, 0, n) {
        s[i + 1] = s[i] + w[i];
    }
    int ans = sum;
    rep(i, 1, n) {
        ans = min(ans, abs(s[i] - (sum - s[i])));
    }
    cout << ans << endl;

    return 0;
}
