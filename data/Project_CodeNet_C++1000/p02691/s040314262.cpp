#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
 
int main() {
  ll n;
  cin>>n;
  vector<int> ab(n+1);
  vin x(n+1);
  map<int,int> y;
  rep(i,0,n){
   // int ab;
    cin>>ab[i+1];
    //a[i+1]=make_pair(i+1,ab);//1 index
    x[i+1]=i+1+ab[i+1];
    y[i+1-ab[i+1]]++;
  }
  
  
  //////////
  ll ans=0;
  
  rep(i,1,n+1){
    if(y[x[i]]>0){
     y[x[i]-2*ab[i]]--;
      ans+=y[x[i]];
     // cout<<x[i]<<endl;
    }
   // cout<<x[i]<<endl;
  }
  
  
  
  
  
  
  
  
  
  
  
  cout<<ans<<endl;
}