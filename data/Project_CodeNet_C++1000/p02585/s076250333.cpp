#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    ll n, K;
    cin >> n >> K;
    int p[n];
    rep(i,n){
        cin >> p[i];
        p[i]--;
    }
    ll a[n];
    rep(i,n)cin >> a[i];
    ll ans = -1001001001001001001;
    rep(i,n){
        ll dp[n] = {};
        int now = i;
        ll loop = 0;
        ll sum = 0;
        rep(j,n){
            if(j > 0) dp[j] = dp[j-1];
            dp[j] += a[now];
            now = p[now];
            if(now == i){
                loop = j + 1;
                sum = max(sum, dp[j]);
                break;
            }
        }
        rep(j,loop){
            if(j+1>K)break;
            ll tmp = (K-(j+1))/loop*sum+dp[j];
            ans = max(ans,tmp);
        }
    }
    cout << ans << endl;
    return 0;
}


