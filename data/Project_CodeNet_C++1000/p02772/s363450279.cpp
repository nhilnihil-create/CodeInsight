#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int MAXN = 1e5 + 10;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    bool f = true;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 1) continue;
        if (x % 3 != 0 && x % 5 != 0) f = false;
    }
    if (f) cout << "APPROVED";
    else cout << "DENIED";
    return 0;
}
