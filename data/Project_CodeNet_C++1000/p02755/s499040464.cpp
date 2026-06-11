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
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 10000; i++) {
        if ((i * 8) / 100 == a && (i * 10) / 100 == b) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
