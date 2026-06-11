#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;

  for(int k=0;k<n;k++){
    int y,m,d;
    cin>>y>>m>>d;
    int ans=0;
    for(int i=y+1;i<1000;i++){
      if(i%3==0){
        ans+=200;
      }else{
        ans+=195;
      }
    }

    for(int i=m+1;i<11;i++){
      if(y%3==0){
        ans+=20;
      }else{
        if(i%2==0){
          ans+=19;
        }else{
          ans+=20;
        }
      }
    }

    if(y%3==0){
      ans+=20-d;
    }else{
      if(m%2==0){
        ans+=19-d;
      }else{
        ans+=20-d;
      }
    }
    cout<<ans+1<<endl;
  }
  return 0;
}