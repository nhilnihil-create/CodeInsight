#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>
#include <cstdint>



#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n-1); i >= 0; i--)
#define repi(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rrepi(i,a,b) for(ll i=(ll)(b);i>=(ll)(a);i--)

#define all(x) (x).begin(),(x).end()

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  ll p=0,z=0;;
  rep(i,n){if(a[i]>0)p++;if(a[i]==0)z++;}
  sort(all(a));
  vector<ll>wari(n);
  if(z==0&&(p==0||p==n)){//saidaimuri
    if(p==n){
      wari[0]=-1;
      repi(i,1,n)wari[i]=1;
    }
    else{
      wari[n-1]=1;
      rep(i,n-1)wari[i]=-1;
    }
  }
  else{
    rep(i,n){
      if(a[i]<0)wari[i]=-1;
      else wari[i]=1;
    }
  }
  ll res=0;
  rep(i,n)res+=a[i]*wari[i];
  cout<<res<<endl;
  int id=0;
  rep(i,n-1){
    if(wari[i]==-1&&wari[i+1]==1)id=i;
  }
  rep(i,n-id-2){
    cout<<a[id]<<" "<<a[id+i+1]<<endl;
    a[id]-=a[id+i+1];
  }
  cout<<a[n-1]<<" "<<a[id]<<endl;
  a[n-1]-=a[id];
  rep(i,id){
    cout<<a[n-1]<<" "<<a[i]<<endl;
    a[n-1]-=a[i];
  }


  return 0;

}
