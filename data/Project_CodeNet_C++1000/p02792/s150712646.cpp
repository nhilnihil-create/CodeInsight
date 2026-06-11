#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
int cnt[10][10];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    for (int i=1; i<=N; i++) {
        string j = to_string(i);
        int f = j[0]-'0';
        int l = j[j.size()-1]-'0';
        cnt[f][l]++;
    }
    int ans = 0;
    rep(i, 10) rep(j, 10) ans += cnt[i][j]*cnt[j][i];
    cout << ans << endl;
}