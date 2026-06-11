#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int)3e5, MOD = (int)1e9 + 7, INF = (int)3e18;

main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map <string ,int> mp;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        mp[s]++;
    }
    cout << mp.size();
    return 0;  
}