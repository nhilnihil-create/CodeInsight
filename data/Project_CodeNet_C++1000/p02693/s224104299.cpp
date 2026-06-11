#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
typedef std::bitset<6> bit;
 
int main(){
  int K,A,B,Ksub=0,flug=0;
  cin>>K>>A>>B;
  int i=1;
    while(Ksub<=B){
      Ksub=K*i;
     // cout<<Ksub<<A<<B<<endl;
      if(Ksub>=A && Ksub<=B){
        flug=1;
        break;
      }
      i++;
    }
  
  if(flug==1) cout<<"OK";
  else cout <<"NG";
  
  return 0;
}