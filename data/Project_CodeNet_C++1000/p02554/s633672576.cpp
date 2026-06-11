#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

const ll mod=1e9+7;
int main(){
  int n;
  cin>>n;

  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  ll a=1,b=1,c=1;
  rep(i,n) a=a*10%mod;
  rep(i,n) b=b*9%mod;
  rep(i,n) c=c*8%mod;

  ll ans=(a-2*b+c)%mod;
  while(ans<0){
    ans+=mod;
  }
  cout<<ans<<endl;
  return 0;
}
