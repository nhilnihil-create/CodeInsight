#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,ans=0,p;cin>>n>>p;
  string s;cin>>s;
  if(p==2||p==5) {
    for(ll pos=n-1;pos>-1;pos--)
      if((s[pos]-'0')%p==0) ans+=pos+1;
  }
  else {
    ll digit=1,val=0;
    lvector mods(p,0);
    for(ll pos=n-1;pos>-1;pos--) {
      val=(val+(s[pos]-'0')*digit)%p;
      digit=(digit*10)%p;
      mods[val]++;
    }
    ans+=mods[0];
    for(ll i:mods) ans+=i*(i-1)/2;
  }
  print(ans);
  return 0;
}