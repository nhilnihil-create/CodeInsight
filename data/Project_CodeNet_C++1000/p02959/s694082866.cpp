#include <bits/stdc++.h>
using namespace std;

#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )

const int INF = 1e9;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int main() {

    int n;
    cin >> n;
    vi a(n + 1);
    vi b(n);
    fo(i, n + 1) cin >> a[i];
    fo(i, n) cin >> b[i];

    ll ans = 0;

    fo(i, n) {
        ans += min(b[i], a[i]);
        b[i] -= min(b[i], a[i]);
        ans += min(b[i], a[i + 1]);
        a[i + 1] -= min(b[i], a[i + 1]);
    }

    cout << ans << endl;

    return 0;
}