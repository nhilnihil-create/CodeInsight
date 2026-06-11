#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int n;
    cin>>n;
    vll dp(n+1,1e10);
    dp[0]=-1;
    rep(i,n){
        ll a;
        cin>>a;
        auto index=lower_bound(all(dp),a)-dp.begin();
        dp[index]=a;
    }
    int ans=0;
    for (int i=1;i<n+1;i++){
        if (dp[i]==1e10){
            ans=i-1;
            break;
        }
    }
    if (ans==0)cout<<n<<endl;
    else cout<<ans<<endl;


    return 0;
}
