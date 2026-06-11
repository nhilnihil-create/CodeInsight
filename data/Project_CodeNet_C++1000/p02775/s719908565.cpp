#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int ans=0;
  int temp=0;
  for(int i=S.length()-1;i>=0;i--){
    if((S.at(i)-'0')+temp>5){
      ans+=10-(S.at(i)-'0'+temp);
      temp=1;
    }
    else if((S.at(i)-'0')+temp==5 && i>0){
      if(S.at(i-1)-'0'>4){
        ans+=10-(S.at(i)-'0'+temp);
        temp=1;
      } 
      else{
      ans+=(S.at(i)-'0')+temp;
      temp=0;        
      }      
    }
    else{
      ans+=(S.at(i)-'0')+temp;
      temp=0;
    }
    //cout<<i<<" "<<ans<<endl;
  }
  cout<<ans+temp<<endl;
  return 0;
}
