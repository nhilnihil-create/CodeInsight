#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PP;
const ll MOD = 998244353;
ll T[100005]={0};
int main(){
  int n;cin>>n;
  ll max=0;
  for(int i=1;i<=n;i++){
    ll k;
    cin>>k;
    if(k>max)max=k;
    if((i==1&&k!=0)||(i!=1&&k==0)){
      cout<<0<<endl;
      return 0;
    }
    T[k]++;
  }
  ll ans=1;
  for(int i=1;i<=max;i++){
    for(int j=1;j<=T[i];j++){
      ans*=T[i-1];
      ans%=MOD;
    }
  }
  cout<<ans<<endl;
}
