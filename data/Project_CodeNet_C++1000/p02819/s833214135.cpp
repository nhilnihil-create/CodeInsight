#include <iostream>
using namespace std;
int main(){
  int x;
  cin >> x;
  int i;
  int f = 0;
  while(1){
    f = 0;
    for(i=2;i<x;i++){
      if(x%i==0) f=1;
    }
    if(f==1) x++;
    else{
      cout << x << "\n";
      return 0;
    }
  }
}