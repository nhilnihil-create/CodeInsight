#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;
    vector<int> v(n, 0);
    vector<int> cnt(1e6 + 5, 0); 
    int mx = -1;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
        cnt[v[i]]++;
    }

    vector<int> dp(mx + 1, 0);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ll temp = v[i];
        while(temp + v[i] <= mx) {
            temp = temp + v[i];
            dp[temp] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        if(dp[v[i]] == 0 && cnt[v[i]] == 1) ans++; 
    }

    cout << ans << endl;
    

    return 0;
}