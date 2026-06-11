#include<iostream>
#include<math.h>
using namespace std;
int main(){
  int n; cin >> n;
  for(double i = 1; i <= n; i++){
    if(floor(i * 1.08) == n){
      cout << i;
      return 0;
    }
  }
  cout << ":(";
}
    
    
    