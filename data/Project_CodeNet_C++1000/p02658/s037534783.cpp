#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int a,ans=1,max=1e18;
  int n;
  bool flag=false;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a;
    if(!a){
      ans=0;
      flag=false;
    }
    else if(ans>max/a)flag=true;
    ans*=a;
  }
  if(flag)cout<<"-1"<<endl;
  else cout<<ans<<endl;
  return 0;
}
