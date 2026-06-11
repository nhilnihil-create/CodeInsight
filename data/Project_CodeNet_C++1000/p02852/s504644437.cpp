#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string s;
    cin >> n >> m >> s;
    int _=0;
    n++;
    for(int i=0; i< n; i++){
        if(s[i]=='1') _++;
        else _ = 0;
        if(_==m){
            cout << -1;
            return 0;
        }
    }
    int pre[n+1], dp[n+1];
    for(int i=0; i<n; i++){
        int j= i;
        while(s[j]=='1') j++;
        for(int t=i; t<=j; t++)
            pre[t] = j;
        i=j;
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i=1; i<=n; i++)
        if(s[i]=='0')
            dp[i] = 1+dp[pre[max(0, i-m)]];
    vector<int> res;
    for(int i=n-1; i>0;){
        int p=max(0, i-m);
        while(dp[p]==-1) p++;
        res.push_back(i-p);
        i=p;
    }
    for(int i=dp[n-1]-1; i>=0; i--)
        cout << res[i] << " ";
    return 0;
}
