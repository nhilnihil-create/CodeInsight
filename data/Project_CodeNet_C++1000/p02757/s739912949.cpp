#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (int)(n); i++)
const ll INF = 1e18;
const ll mod = 1e9+7;

int main() {
    ll n,p;
    string s;
    cin>>n>>p>>s;
    if (10%p==0){
      ll ans=0;
      rep(i,n){
        if ((s[i]-'0')%p==0) ans+=(i+1);
      }
      cout<<ans;
      return 0;

    }
    else{
      map<ll,ll>mp;
      ll fac=1;
      vector<ll> v(n+1,0);
      ll ans=0;
      mp[0]++;

      for(ll i=n-1;i>=0;i--){
        ll now=s[i]-'0';
        now*=fac;
        now%=p;
        now+=v[i+1];
        now%=p;
        v[i]=now;
        ans+=mp[now];
        mp[now]++;
        fac*=10;
        fac%=p;

      //  cout<<ans<<endl;

      }

      cout<<ans;
    }


}
