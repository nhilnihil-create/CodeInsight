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


int main() {
   int n;
  cin>>n;
   vin p(n);
  rep(i,n) cin>>p[i];
  //////////
  int ans=0;
  for(int i=1;i<=n-2;i++){
    if(p[i]>p[i-1] &&p[i]<p[i+1]) ans++;
    else if(p[i]<p[i-1] &&p[i]>p[i+1]) ans++;
  }
  cout<<ans<<endl;
}