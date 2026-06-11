#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;

int main(void){
  long long n,m,k;
  long long tmp=0;
  long long i,j;
  long long res=0;
  
  cin>>k;
  if(k%2==0 || k%5==0){
    res=-1;
  }
  else{
    for(i=0;;i++){
      tmp=(tmp*10+7)%k;
      //cout<<tmp<<" "<<tmp%k<<endl;
      if(tmp==0){
        res=i+1;
        break;
      }
    }
  }
  
  
  cout<<res<<endl;
  return 0;
  
}