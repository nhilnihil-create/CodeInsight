#include <iostream>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  n = n%10;
  
  if(n==3){cout << "bon";}
  else if(n==0 || n==1 || n==6 || n==8){
    cout << "pon";
  }
  else{cout << "hon";}
  
  return 0;
}
