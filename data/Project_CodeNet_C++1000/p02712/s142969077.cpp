#include<iostream>
using namespace std;
int main(){
  unsigned long long n,ans=0;
  cin>>n;
  for(int i=1;i<=n;i++){
    if(i%15==0){
      continue;
    }
    else if(i%3==0){
      continue;
    }
    else if(i%5==0){
      continue;
    }
    else{
      ans+=i;
    }
  }
  cout<<ans<<endl;
  return 0;
}