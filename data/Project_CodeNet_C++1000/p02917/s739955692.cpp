#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
int n;
int a[N], b[N];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) cin >> b[i];
    int ans = 0;
    for(int i = 2; i < n; i++) {
        ans += min(b[i - 1], b[i]);
    }
    ans += b[1] + b[n - 1];
    cout << ans;
}