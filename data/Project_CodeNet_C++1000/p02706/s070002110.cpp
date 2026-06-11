#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int A = 5e2 + 2;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        sum += x;
    }
    if (n - sum < 0) return cout << -1, 0;
    cout << n - sum;
    return 0;
}