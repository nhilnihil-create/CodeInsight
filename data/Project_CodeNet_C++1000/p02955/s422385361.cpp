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
struct edge{ll to,cost;};

int main() {
  ll ans=1;
  ll n,k;
  cin >> n >> k;
  vl a(n);
  ll sum=0;
  rep(i,n){
    cin >> a[i];
    sum += a[i];
  }
  ll z=sqrt(sum);
  vl p(100000);
  ll j=0;
  FOR(i,1,z+1){
    if(sum%i==0){
      p[j]=i;
      j++;
    }
  }
  j--;
  ll x;
  if(sum==z*z){
    p.resize(2*j+1);
    FOR(i,j+1,2*j+1){
      p[i]=sum/p[2*j-i];
    }
    x=2*j+1;
  }
  else{
    p.resize(2*j+2);
    FOR(i,j+1,2*j+2){
      p[i]=sum/p[2*j+1-i];
    }
    x=2*j+2;
  }
  vl b(n);
  vl c(n);
  rep(i,x){
    ll MIN=INF;
    rep(j,n){
      b[j]=a[j]%p[i];
    }
    sort(b.begin(),b.end());
    rep(j,n){
      c[j]=(p[i]-b[j])%p[i];
    }
    vl sumb(n);
    vl sumc(n);
    sumb[0]=b[0];
    sumc[n-1]=c[n-1];
    rep(i,n-1){
      sumb[i+1]=sumb[i]+b[i+1];
      sumc[n-2-i]=sumc[n-1-i]+c[n-2-i];
    }
    rep(j,n-1){
      MIN=min(MIN,max(sumb[j],sumc[j+1]));
    }
    if(MIN<=k){
      ans=p[i];
    }
  }
  cout << ans << endl;
}
