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
const int mod = 1e9 + 7;
const int MAXN = 5e5 + 5;

int main() {
    int x;
    cin >> x;
    int ans = 0;
    ans += (x / 500) * 1000;
    x %= 500;
    ans += (x / 5) * 5;
    cout << ans;
    return 0;
}
