#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

signed main() {
    int n;
    cin>>n;
    int a[222222];
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    int ans[222222] = {};
    for (int i = n; i > 0; i--) {
        for (int j = i * 2; j <= n; j += i) {
            a[i] += ans[j];
        }
        if (a[i] % 2) {
            ans[i] = 1;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i]) cnt++;
    }
    cout<<cnt<<endl;
    for (int i = 1; i <= n; i++) {
        if (ans[i]) cout<<i<<' ';
    }
    cout<<endl;
}