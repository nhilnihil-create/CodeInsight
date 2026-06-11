#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define endl "\n"
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i, n) {
        cin >> v[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] >= k)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
