#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll K,ans=0; cin>>K;
    for(int i=1;i<=K;i++){
        for(int j=1;j<=K;j++){
            for(int k=1;k<=K;k++){
                ans+=__gcd(i,__gcd(j,k));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}