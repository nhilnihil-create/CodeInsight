/*
     Author:Raghav Bansal
     IIIT Una
                  */
#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define BOLT ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define X first
#define Y second
#define endl "\n"
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> ans;
    if ((n & 1) ^ 1) {
        int a = 1, b = n / 2;
        while (a < b) {
            ans.pb({a, b});
            a++; b--;
        }
        a = n / 2 + 1, b = n - 1;
        while (a < b) {
            ans.pb({a, b});
            a++; b--;
        }
    } else {
        int a = 1, b = n;
        while (a < b) {
            ans.pb({a, b});
            a++; b--;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}
int32_t main() {
    BOLT;
    solve();
}