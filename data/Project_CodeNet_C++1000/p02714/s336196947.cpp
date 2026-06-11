#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<int> sufr(n + 1), sufg(n + 1), sufb(n + 1);
    for (int i = n - 1; i >= 0; i--) sufr[i] = sufr[i + 1] + (a[i] == 'R');
    for (int i = n - 1; i >= 0; i--) sufg[i] = sufg[i + 1] + (a[i] == 'G');
    for (int i = n - 1; i >= 0; i--) sufb[i] = sufb[i + 1] + (a[i] == 'B');
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) continue;
            if ((a[i] == 'R' && a[j] == 'G') || (a[i] == 'G' && a[j] == 'R')) {
                ans += sufb[j + 1];
                if (j + j - i < n && a[j + j - i] == 'B') ans--;
            }
            if ((a[i] == 'B' && a[j] == 'G') || (a[i] == 'G' && a[j] == 'B')) {
                ans += sufr[j + 1];
                if (j + j - i < n && a[j + j - i] == 'R') ans--;
            }
            if ((a[i] == 'R' && a[j] == 'B') || (a[i] == 'B' && a[j] == 'R')) {
                ans += sufg[j + 1];
                if (j + j - i < n && a[j + j - i] == 'G') ans--;
            }
        }
    }
    cout << ans;
    return 0;
}

