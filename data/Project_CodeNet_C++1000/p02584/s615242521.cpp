#include<iostream>
using namespace std;

int main(){
  long long X,K,D;
  cin >> X >> K >> D;
  
  if (X<0){
    X=-X;
  }
  
  long long ans=X;
  if (X/D>K){
    ans=X-K*D;
  }
  else{
    if ((X/D)%2 == K%2){
      ans=X%D;
    }
    else{
      ans=D-X%D;
    }
    
  }
  
  cout << ans << endl;
  
  return 0;
}
