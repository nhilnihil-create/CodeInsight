#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N, M; cin >> N >> M;
    string S; cin >> S;
    vector<int> ans;
    bool abailable = true;
    reverse(S.begin(), S.end());
    vector<int> dp(N+1);
    dp[0] = -1;
    int now = 1;
    rep(i, N){
        if(S[i] == '1') dp[i+1] = dp[i];
        else dp[i+1] = i+1;
        if(i - dp[i+1] + 1 >= M) now = -1;
    }
    if(now < 0){
        cout << now << endl;
        return 0;
    }

    while(now <= N && now >= 0){
        if(now+M > N){
            ans.push_back(N+1 - now);
            break;
        }
        ans.push_back(dp[now+M] - now);
        now = dp[now+M];
    }
    reverse(ans.begin(), ans.end());
    rep(i, ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
