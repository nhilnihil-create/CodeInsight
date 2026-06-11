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
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && c != a) {
        cout << "Yes";
        return 0;
    }
    if (a == c && b != a) {
        cout << "Yes";
        return 0;
    }
    if (b == c && b != a) {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}
