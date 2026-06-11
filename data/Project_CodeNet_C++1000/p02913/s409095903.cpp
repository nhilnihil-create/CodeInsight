#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll N;
    string S;
    cin >> N >> S;
    ll ans = 0;
    VVL dp(N+1, VL(N+1, 0));
    for(ll i = N-1; i >= 0; i--){
        for(ll j = N-1; j > i; --j){
            if(S[i] == S[j]) dp[i][j] = max(dp[i][j], dp[i+1][j+1] + 1);
             ans = max(ans, min(dp[i][j], j - i));
        }
    }
    cout << ans << endl;
    return 0;
}