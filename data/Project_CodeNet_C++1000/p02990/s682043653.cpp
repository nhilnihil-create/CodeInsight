// ABC132-D
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
namespace you {
    std::string to_string(char val) {
        return std::string(1, val);
        // return std::string{val};
        // you::to_string(char)
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    ll mod=pow(10,9)+7;
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> dp(2010,vector<ll>(2010,0));
    rep(i,2010) dp[i][0]=1;
    for(int i=1;i<2010;i++){
        for(int j=1;j<2010;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
    for(int i=1;i<=k;i++){
        ll ans=0;
        if(i<=n-k+1) ans=dp[n-k+1][i]*dp[k-1][i-1]%mod;
        cout<<ans<<endl;
    }
    return 0;
}