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
    VL a(N), f(N);
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> f[i];
    sort(ALL(a));
    sort(ALL(f), greater<ll>());
    ll L = -1, R = 1e18;
    while(R - L > 1){
        // cerr << L << " " << R << endl; 
        bool flag = true;
        ll M = L + (R - L) / 2;
        ll k = K;
        rep(i, 0, N){
            if(a[i] * f[i] > M){
                ll rem = a[i] * f[i] - M;
                k -= (rem + f[i] - 1) / f[i];
            }
            if(k < 0){
                flag = false;
                break;
            }
        }
        if(flag) R = M;
        else L = M;
    }
    cout << max(0LL, R) << endl;
    return 0;
}