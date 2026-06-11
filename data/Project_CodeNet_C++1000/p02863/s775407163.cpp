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


ll dp1[5000][5000];
ll dp2[5000][5000];

int main(){

    // read input
    ll N, T;
    cin >> N >> T;
    VL A(N+1), B(N+1);
    rep(i, 1, N+1) cin >> A[i] >> B[i];

    // initialize
    rep(i, 0, 5000){
        rep(j, 0, 5000){
            dp1[i][j] = 0;
            dp2[i][j] = 0;
        }
    }

    // knapsack 1 to i
    rep(i, 1, N+1){
        rep(t, 0, T){
            if(t >= A[i]){
                dp1[i][t] = max(dp1[i-1][t], dp1[i-1][t-A[i]] + B[i]);
            }else{
                dp1[i][t] = dp1[i-1][t];
            }
        }
    }

    // knapsack N to i
    for(ll i = N; i > 0; i--){
        rep(t, 0, T){
            if(t >= A[i]){
                dp2[i][t] = max(dp2[i+1][t], dp2[i+1][t-A[i]] + B[i]);
            }else{
                dp2[i][t] = dp2[i+1][t];
            }
        }
    }

    ll ans = 0;
    rep(i, 1, N+1){
        ll mx = 0;
        rep(t, 0, T){
            mx = max(mx, dp1[i-1][t] + dp2[i+1][T-1-t]);
        }
        ans = max(ans, mx + B[i]);
    }

    cout << ans << endl;
    return 0;
}