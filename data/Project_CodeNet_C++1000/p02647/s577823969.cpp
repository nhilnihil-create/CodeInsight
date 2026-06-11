#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i<(n);i++)
#define fore(i,a) for(auto &i:a)
#define debug(a,b) cout << "debug : " << a << " , "<< b << endl
using ll=long long;
const ll INF=1LL<<60;
const ll mod=1E9+7;

int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll>a(n),b(n,0);
  rep(i,n)cin >> a[i];
  int cnt=0;
  do{
    rep(i,n)b[i]=0;
    rep(i,n){
      ll r,l;
      l=max((ll)0,i-a[i]);
      r=min(n-1,i+a[i]);
      b[l]++;
      if(r+1<n)b[r+1]--;
    }
    rep(i,n){
      if(i!=n-1)b[i+1]+=b[i];
      a[i]=b[i];
    }
    cnt++;
    if(cnt==k)break;
  }while(a[0]!=n);

  rep(i,n)cout << a[i] << " ";
}
