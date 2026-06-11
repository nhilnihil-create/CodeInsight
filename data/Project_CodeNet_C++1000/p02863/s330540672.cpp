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
    ll N, T;
    cin >> N >> T;

    VL A(N+1), B(N+1);
    rep(i, 1, N+1) cin >> A[i] >> B[i];

    VVL dp1(3050, VL(3050, 0));
    rep(i, 1, N+1){
        rep(t, 0, T){
            if(t < A[i]) dp1[i][t] = dp1[i-1][t];
            else dp1[i][t] = max(dp1[i-1][t], dp1[i-1][t-A[i]] + B[i]);
        }
    }

    VVL dp2(3050, VL(3050, 0));
    for(ll i = N; i > 0; i--){
        rep(t, 0, T){
            if(t < A[i]) dp2[i][t] = dp2[i+1][t];
            else dp2[i][t] = max(dp2[i+1][t], dp2[i+1][t-A[i]] + B[i]);
        }
    }

    ll ans = 0;
    rep(i, 1, N+1){
        rep(t, 0, T){
            ans = max(ans, dp1[i-1][t] + dp2[i+1][T-t-1] + B[i]);
        }
    }

    cout << ans << endl;
    return 0;
}