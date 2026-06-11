#include <iostream>
using namespace std;
int main(){
  int n, d;
  cin >> n >> d;
  for(int i=1; i<=n; i++){
    if(i*(i+d-(i-d)+1)>=n){
      cout << i;
      break;
    }
  }
  return 0;
}