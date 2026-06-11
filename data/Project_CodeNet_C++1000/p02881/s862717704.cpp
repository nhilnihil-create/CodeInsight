#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=1;i<=n;i++)
using ll = long long;
int main(){
ll n,ans;
  cin>>n;
  ans=n;
  rep(i,sqrt(n)){
    if(n%i == 0){
      ans=min(i+n/i-2,ans);
    }
  }
  cout<<ans<<endl;
}
