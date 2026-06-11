#include <bits/stdc++.h>
using namespace std;
int main(){
  int64_t X, N, D;
  cin>>X>>N>>D;
  int64_t a;
  X=abs(X);
  if(abs(X-D*(X/D))<abs(X-D*(X+D-1)/D)){
    a=X/D;
  }
  else{
    a=(X+D-1)/D;
  }
  if(N<=a){
    cout<<abs(abs(X)-abs(D*N))<<endl;
  }
  else{
    if((N-a)%2==0){
      cout<<abs(X-D*a)<<endl;
    }
    else{
      cout<<D-abs(X-D*a)<<endl;
    }
  }
}
  