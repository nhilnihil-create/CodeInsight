#include<iostream>
using namespace std;
int main(){
  int n;
  while(cin>>n,n){
    int ans=0,cnt=0;
    for(int i=n+1;i<=2*n;i++){
      for(int j=2;j*j<=i;j++)if(i%j==0)cnt=1;
      if(cnt==0)ans++;
      cnt=0;
    }
    cout<<ans<<endl;
  }
  return 0;
}