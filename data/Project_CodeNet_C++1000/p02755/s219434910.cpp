#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,a=0;
  cin>>A>>B;
  for(int i=0;i<10000;i++){
    if(int(i*0.08)==A && int(i*0.10)==B){
      a=1;
      cout<<i<<endl;
      break;
    }
  }
  if(a==0)
    cout<<-1<<endl;
}