#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  ll n;
  cin>>n;
  vector<ll> a(n+1);
  vector<ll> b(n);
  rep(i,n+1) cin>>a[i];
  rep(i,n)   cin>>b[i];
  ll ans=0;
  rep(i,n){
    if(a[i]>=b[i]){
      ans+=b[i];
      continue;
    }
    if(a[i]<b[i]&&b[i]<=a[i]+a[i+1]){
      ans+=b[i];
      a[i+1]-=b[i]-a[i];
      continue;
    }
    if(a[i]<b[i]&&b[i]>a[i]+a[i+1]){
      ans+=a[i]+a[i+1];
      a[i+1]=0;
      continue;
    }
  }
  cout<<ans<<endl;
}