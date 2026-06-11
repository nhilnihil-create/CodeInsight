#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t T1,T2,A1,A2,B1,B2;
  cin>>T1>>T2>>A1>>A2>>B1>>B2;
  if(T1*A1+T2*A2==T1*B1+T2*B2){
    cout<<"infinity"<<endl;
  }
  else{
    if(T1*A1+T2*A2<T1*B1+T2*B2){
      swap(A1,B1);
      swap(A2,B2);
    }
    if(A1>B1){
      cout<<"0"<<endl;
    }
    else{
      int64_t D=T1*A1+T2*A2-(T1*B1+T2*B2);
      int64_t C=T1*(B1-A1);
      if(C%D){
        cout<<(C/D)*2+1<<endl;
      }
      else{
        cout<<(C/D)*2<<endl;
      }
    }
  }
}