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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for (auto &c : a) {
        cin >> c;
        sum += c;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (a[i] * 4 * m >= sum);
    }
    cout << (cnt >= m ? "Yes" : "No");
    return 0;
}
