#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll n;
  cin >> n;
  ll ans=1;
  ll a=n-1;
  for(ll i=2;i*i<=a;i++){
    if(a%i==0){
      if((i*i)!=a){
          ans +=2;
        }
      else
        ans +=1;
    }
  }
  vl yakusu(2*sqrt(n)+5,INF);
  ll j=0;
  for(ll i=2;i*i<=n;i++){
    if(i*i!=n){
      if(n%i==0){
        yakusu[j]=i;
        yakusu[j+1]=n/i;
        j +=2;
      }
    }
    else if(n%i==0){
      yakusu[j]=i;
    }
  }
  if(n>2){
    ans++;
  }
  ll c=0;
  ll i=0;
  while(yakusu[i]!=INF){
    c=i;
    i++;
  }
  rep(i,c+1){
    ll m=n;
    ll k=yakusu[i];
    while(m>=k){
      if(m%k==0){
        m /=k;
      }
      else
        m=m%k;
      if(m==1){
        ans++;
      }
    }
  }
  cout << ans << endl;
}