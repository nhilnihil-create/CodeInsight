#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> pref(n+1,vector<int>(10));
    for ( int i=0; i<n; i++ ) {
        pref[i+1] = pref[i];
        pref[i+1][s[i]-'0']++;
    }
    vector<int> prv(10,0);
    long long ans = 0;
    for ( int i=0; i<n; i++ ) {
        int d = s[i] - '0';
        long long l=0, r=0;
        {
            for ( int j = 0; j < 10; j++ ) {
                l += (pref[i][j]>0 && pref[prv[d]][j]==0);
            }
        }
        {
            for ( int j = 0; j < 10; j++ ) {
                r += (pref[n][j] - pref[i+1][j] > 0);
            }
        }
        ans += l*r;
        prv[d] = i;
    }
    cout << ans << '\n';
    return 0;
}

// 242424