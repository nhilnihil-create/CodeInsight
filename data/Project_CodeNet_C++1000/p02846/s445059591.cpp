#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

int main(){
  ll T[2],A[2],B[2];
  cin>>T[0]>>T[1];
  cin>>A[0]>>A[1];
  cin>>B[0]>>B[1];
  ll X=T[0]*A[0]+T[1]*A[1];
  ll Y=T[0]*B[0]+T[1]*B[1];
  
  if(X==Y){
    cout<<"infinity\n";
    return 0;
  }
  if(X>Y&&A[0]>B[0]){
    cout<<0<<endl;
    return 0;
  }
  if(X<Y&&A[0]<B[0]){
    cout<<0<<endl;
    return 0;
  }
  
  ll D=abs(X-Y);
  ll Z=abs(A[0]-B[0])*T[0];
  
  cout<<Z/D*2+(Z%D!=0)<<endl;
  return 0;
}