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
    ll n,ans=99999999999999; cin>>n;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0) ans=min(ans,i+n/i-2);
    }
    cout<<ans<<endl;
    return 0;
}