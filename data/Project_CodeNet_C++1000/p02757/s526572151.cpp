#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(int)n;i++)
typedef long long ll;
using namespace std;
long long modpow(long long a, long long n,ll mod){
  long long r = 1;
  while (n) {
    r = r * ( (n%2)?a:1 ) %mod;
    a = a * a % mod;
    n >>= 1;
  }
  return r;
}

int main(void){
    ll n,mod;cin>>n>>mod;
    string s;cin>>s;
    reverse(s.begin(),s.end());
    ll res=0,now=0;
    if(mod==2||mod==5){
        reverse(s.begin(),s.end());
        rep(i,n){
            ll d=s[i]-'0';
            if(d%mod==0)res+=(i+1);
        }
        cout<<res<<endl;
        return 0;
    }
    map<ll,ll> mp;
    rep(i,n){
        ll t=modpow(10,i,mod);
        ll d=s[i]-'0';
        d*=t;
        d+=now;
        d%=mod;
        mp[d]++;
        now=d;
    }
    for(auto& p:mp){
        ll x=p.first,y=p.second;
        //cout<<x<<" "<<y<<endl;
        if(x==0){
            res+=(y+1)*y/2;
        }else{
            y--;
            res+=(y+1)*y/2;
        }
    }
    cout<<res<<endl;
}