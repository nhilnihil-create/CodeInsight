#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,X;
  bool Y=false;
  cin>>A>>B;
  for(X=0;X<B*20;X++){
    if(X*8/100==A && X/10==B){
      cout<<X<<endl;
      Y=true;
      break;
    }
  }
  if(Y==false){
    cout<<-1<<endl;
  }
}
