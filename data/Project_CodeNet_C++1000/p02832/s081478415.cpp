#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll n,next=1,ans=0; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    rep(i,n){
        if(next==a[i]) next++;
        else ans++;
    }
    if(ans==n) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}