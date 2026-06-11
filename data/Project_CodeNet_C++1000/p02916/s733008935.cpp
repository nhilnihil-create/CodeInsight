#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 25;
int n;
int a[N], b[N], c[N];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i < n; i++) cin >> c[i];
    int ans = 0;
    a[0] = -2;
    for(int i = 1; i <= n; i++) {
        ans += b[a[i]];
        if(a[i] == a[i - 1] + 1) ans += c[a[i - 1]];
    }
    cout << ans;
}