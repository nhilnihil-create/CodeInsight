#include <bits/stdc++.h>
using namespace std;

int main(){
  long A,B,K;cin>>A>>B>>K;
  long Ao,Taka;
  if(K<=A){
    Ao=A-K;
    Taka=B;
  }
  else if(K<=A+B){
    Ao=0;
    Taka=A+B-K;
  }
  else{
    Ao=0;
    Taka=0;
  }
  cout<<Ao<<" "<<Taka<<endl;
}
