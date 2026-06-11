#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n;
    ll ans=INF; 
    cin >> n;
    VL a(n,0),sum(n+1,0);
    rep(i,0,n){
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }
    
    rep(i,0,n){
        ans = min(abs(sum[i+1]-(sum[n]-sum[i+1])),ans);
    }
    cout << ans << endl;
}
