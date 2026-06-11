#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(){
  ll N,A,B;
  cin>>N>>A>>B;
  ll ans=A*(N/(A+B));
  if(N%(A+B)>=A){
    ans+=A;
  }
  if(N%(A+B)<A){
    ans+=N%(A+B);
  }
  cout<<ans<<endl;
}