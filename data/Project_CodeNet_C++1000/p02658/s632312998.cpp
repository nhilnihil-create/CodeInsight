#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll res = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            if (res > 1000000000000000000 / a[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
        res *= a[i];
    }
    cout << res << endl;
}