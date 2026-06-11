#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> a(3, vector<int>(3));
    vector<vector<int>> usd(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[i][j] == x) usd[i][j] = 1;
            }
        }
    }
    bool f = false;
    for (int i = 0; i < 3; i++) {
        if (usd[i][0] && usd[i][1] && usd[i][2]) f = true;
        if (usd[0][i] && usd[1][i] && usd[2][i]) f = true;
    }
    if (usd[0][0] && usd[1][1] && usd[2][2]) f = true;
    if (usd[0][2] && usd[1][1] && usd[2][0]) f = true;
    cout << (f ? "Yes" : "No");
    return 0;
}
