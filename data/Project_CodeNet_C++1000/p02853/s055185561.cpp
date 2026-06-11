#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll x,y,a=100000,ans=0; cin>>x>>y;
    if(3>=x) ans+=a*(4-x);
    if(3>=y) ans+=a*(4-y);
    if(x==1&&y==1) ans+=a*4;
    cout << ans << endl;
    return 0;
}