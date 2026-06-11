//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define ALL(v) (v).begin(), (v).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
//cout << std::fixed << std::setprecision(15) << y << endl;

int main(){
    ll N;
    cin >> N;
    VL a(N);
    rep(i,0,N) cin >> a[i];
    
    ll ans = 0;
    ll ma = 0;
    rep(i,0,N){
        ma = max(ma, a[i]);
        if(a[i] < ma) ans += ma - a[i];
    }
    cout << ans << endl;
    return 0;
}
