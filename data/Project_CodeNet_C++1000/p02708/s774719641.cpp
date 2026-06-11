#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

const int mod=1e9+7;

int main(){
  ll n,k;
  cin>>n>>k;
  ll ans=0;

  for(int i=k;i<=n+1;i++){
    ans=(ans+(n-i+1)*i%mod+1)%mod;
  }
  cout<<ans<<endl;
  return 0;
}