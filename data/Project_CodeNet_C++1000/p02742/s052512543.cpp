#include <bits/stdc++.h>
using namespace std;
string oddeven(long long x){
  long long a;
    a=x/2;
  if(a*2==x){
  return "even";
  }
  else{
  return "odd";
  }
}
int main(){
  long long H,W;
  cin>>H>>W;
  string a,b;
  a=oddeven(H);
  b=oddeven(W);
  if(H==1 || W==1){
  cout<<1<<endl;
  }
  else if(a=="odd" && b=="odd"){
    cout<<H*(W-1)/2+H/2+1<<endl;
  
  }
  else{
  cout<<(H*W)/2<<endl;
      
  }
}