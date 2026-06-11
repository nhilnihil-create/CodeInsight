#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n;
  cin>>n;
  double ans=1;
  if(n%2==0){
    ans/=2;
    cout<<ans<<endl;
  }
  else {
    ans=n+1;
    ans/=2*n;
    cout<<ans<<endl;
  }
  
  return 0;
}