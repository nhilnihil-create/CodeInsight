#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for (ll i=0; i < (ll)(n); i++)

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    ll ans;

    if(b<0&&c>0)ans=b*c;
    else if (a>0&&d<0)ans=a*d;
    else ans=max(a*c,b*d);
    cout<<ans<<endl;
}