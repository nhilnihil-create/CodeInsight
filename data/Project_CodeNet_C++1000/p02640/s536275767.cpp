#include <iostream>
using namespace std;
int main(){
  int x,y;
  cin >> x >> y;
  int i,j;
  for(i=0;i<=x;i++){
    if(i*2+(x-i)*4==y){
      cout << "Yes" << "\n";
      return 0;
    }
  }
  cout << "No" << "\n";
  return 0;
}