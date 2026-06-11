#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000
#define MOD 1000000007

int main(){
  int M;
  cin>>M;
  vector<ll> d(M),c(M);
  for(int i=0;i<M;i++){
    cin>>d.at(i)>>c.at(i);
  }

  ll ans=0;
  for(int i=0;i<M;i++){
    ans+=c.at(i);
  }
  ll sum=0;
  for(int i=0;i<M;i++){
    sum+=c.at(i)*d.at(i);
  }
  while(sum>9){
    ans+=sum/10;
    sum=sum/10+sum%10;
  }
  ans--;
  cout<<ans<<endl;
}
