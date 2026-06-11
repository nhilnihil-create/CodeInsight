
#include <bits/stdc++.h>
#define rep(i,n) for (double i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<double,double> P;
const int INF=1001001001;


int main(){
  ll n;
  cin>>n;
  if (n%2==1){
    cout<<0;
    return 0;
  }
  ll now=10;
  ll ans=0;
  while(now<=n){
    ll temp=n/now;
    ans+=temp;
    now*=5;
  }
  cout<<ans;

}
