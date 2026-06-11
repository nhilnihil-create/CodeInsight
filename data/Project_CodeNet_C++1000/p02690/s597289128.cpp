#include<bits/stdc++.h>
using namespace std;
int main(){
  int X;
  bool H=false;
  cin>>X;
  for(long long A=-200;A<200;A++){
    for(long long B=-200;B<200;B++){
      long long N=A*A*A*A*A;
      long long M=B*B*B*B*B;
      if(N-M==X&&N+M<=100000000){
        cout<<A<<" "<<B<<endl;
        H=true;
        break;
      }
    }
    if(H==true){
      break;
    }
  }
}
