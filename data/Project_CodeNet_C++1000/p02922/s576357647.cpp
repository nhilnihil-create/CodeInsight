#include <bits/stdc++.h>
using namespace std;



int main(){
  int A,B;
  cin>>A>>B;
  
  int kaz=1;
  int mis=A;
  if(B==1){
    cout<<0<<endl;
    return 0;
  }
  while(mis<B){
    kaz++;
    mis+=(A-1);
  }
  cout<<kaz<<endl;
  
  
    
}