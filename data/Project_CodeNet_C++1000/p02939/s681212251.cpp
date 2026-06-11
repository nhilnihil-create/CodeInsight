#include<iostream>
#include<string>
using namespace std;
int main(){

  string S;
  cin>>S;
  string sub1;
  string sub2;
  sub1=S[0];
  int ans=0;
  for(size_t i=1;i<=S.length()-1;i++){
  
    sub2=S[i];
    if(sub1==sub2){
    
      if(i==S.length()-1){
      
         break;
      }
      sub2+=S[i+1];
      i++;
    }
    else sub2;
    //cout<<sub1<<" "<<sub2<<endl;
    sub1=sub2;
    ans++;
  }
  cout<<ans+1;
}