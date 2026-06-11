#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back
int dp[100005], pv[100005];
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    cin >> s;

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    deque<int> dq;
    dq.push_back(0);
    n++;
    for(int i=1;i<n;i++){
        if(s[i] == '1') continue;
        while(!dq.empty() && i-dq.front() > m) dq.pop_front();
        if(dq.empty()) continue;
        dp[i] = dp[dq.front()]+1;
        pv[i] = dq.front();
        while(!dq.empty() && dp[dq.back()] > dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    if(dp[n-1] == -1) printf("-1\n");
    else{
        vector<int> ans;
        int u = n-1;
        while(u != 0){
            ans.eb(u-pv[u]);
            u = pv[u];
        }
        reverse(all(ans));

        for(int i=0;i<sz(ans);i++) printf("%d ", ans[i]);
        printf("\n");
    }
}