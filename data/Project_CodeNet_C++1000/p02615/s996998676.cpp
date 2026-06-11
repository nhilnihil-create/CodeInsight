#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
#define fr first
#define sc second
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

using namespace std;

const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(all(v));

    reverse(all(v));

    ll ans = v[0];

    for (int i = 2; i < n; i++) {
        ans += v[i / 2];
    }

    cout << ans;

    return 0;
}
