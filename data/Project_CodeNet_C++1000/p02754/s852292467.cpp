#include <bits/stdc++.h>
using namespace std;

int main(){
  unsigned long long N,A,B,C,D,ans;
  cin>>N>>A>>B;
 C=N/(A+B);
 D=N%(A+B);
  ans=C*A;
  if(D<=A){
    ans+=D;
  }else{
    ans+=A;
  }
  cout<<ans<<endl;
}
    