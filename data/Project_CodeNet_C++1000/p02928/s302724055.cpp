//#define _GLIBCXX_DEBUG
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
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    ll n, k;
    cin >> n >> k;
    VL a(n);
    rep(i,0,n) cin >> a[i];
    ll c_front = 0, c_back = 0;
    rep(i,0,n){
        rep(j,i+1,n){
            if(a[i] > a[j]){
                c_front++;
            }else if(a[i] < a[j]){
                c_back++;
            }
        }
    }
    //naibu 
    k = k % MOD;
    ll ans = c_front * k;
    //gaibu kC2 
    ll kk = (k * (k - 1) / 2) % MOD;
    ans += (c_front + c_back) * kk; //c_backが2ブロック間で発生する数 //c_frontが外部ブロック内で発生する数
    ans = ans % MOD;
    cout << ans << endl;
    return 0;
}
