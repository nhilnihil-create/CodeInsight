#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 1; i <= n-m; i++){
        bool flag = true;
        rep(j, m)
        {
            if(s[i+j]=='0'){
                flag =false;
                break;
            }
        }
        if(flag){
            cout << -1 << endl;
            return 0;
        }
    }
    int dp[n+1] = {};
    reverse(s.begin(), s.end());
    int now = 0;
    vector<int> ans;
    while (now != n)
    {
        for(int i = m; i > 0; i--){
            if(now + i > n)continue;
            if(s[now+i] == '1') continue;
            dp[now + i] = dp[now] + 1;
            now += i;
            ans.push_back(i);
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
}