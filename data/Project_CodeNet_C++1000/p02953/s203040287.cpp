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
    ll n,maxi=0; cin>>n;
    bool can=true;
    for(int i=0;i<n;i++){
        ll a; cin>>a;
        if(a < maxi-1) can=false;
        maxi=max(maxi,a);
    }
    if(can) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}