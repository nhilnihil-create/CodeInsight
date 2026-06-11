#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n, m;
    cin >> n >> m >> s;
    n = s.length();
    int q = 0;
    for(int i=0; i<n; i++) {
        if(s[i]=='1')
            q++;
        else
            q = 0;
        if(q==m) {
            cout << -1;
            return 0;
        }
    }
    int pre[n+1];
    for(int i=0; i<n; i++){
        int t= i;
        while(s[t] == '1') t++;
        for(int jj = i; jj<t; jj++)
            pre[jj]  = t;
    }
    int dp[n];
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for(int i=1; i<n; i++)
        if(s[i] == '0') {
            if(dp[max(0, i-m)]==-1)
                dp[i] = dp[pre[max(0, i-m)]]+1;
            else
                dp[i] = dp[max(0, i-m)]+1;
        }
    vector<int> res;
    for(int i = n-1; i>0; ) {
        int p = max(0, i-m);
        while(dp[p] == -1 || dp[i] - dp[p] > 1)
            p++;
        res.push_back(i-p);
        i = p;
    }
    for(int i=dp[n-1]-1; i>=0; i--)
        cout << res[i] << " ";
    return 0;
}
