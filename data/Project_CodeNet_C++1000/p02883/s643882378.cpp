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
    ll N, K;
    cin >> N >> K;
    VL A(N), F(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> F[i];

    sort(ALL(A));
    sort(ALL(F), greater<ll>());

    ll L = -1, R = 1e18;
    while(R - L > 1){
        ll M = L + (R - L)/2;
        ll tk = K;
        rep(i, 0, N){
            if(A[i] * F[i] > M){
                tk -= (A[i] * F[i] - M + F[i] - 1) / F[i];
            }
        }
        if(tk < 0) L = M;
        else R = M;
    }
    cout << R << endl;
    return 0;
}