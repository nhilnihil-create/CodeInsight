#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define endl "\n"
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    rep(i, n) {
        cin >> v[i];
    }
    int ans = 0, sum = 0;
    for(int i = 1; i <= n + 1; i++) {
        if(sum <= x)
            ans++;
        sum += v[i - 1];
    }
    cout << ans;
    return 0;
}
