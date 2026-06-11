#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }


int main() {
 int n;
  cin>>n;
  vin w(n);
  rep(i,n) cin>>w[i];
  //////
  int sum=0;
  rep(i,n) sum+=w[i];
  int ans=inf;
  rep(i,n){
   int cnt=0; 
    rep(j,i+1){
      cnt+=w[j];
    }
  //  cout<<cnt<<endl;
    cnt=abs(2*cnt-sum);
    
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}