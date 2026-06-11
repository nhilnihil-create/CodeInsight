#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  int i,j;
  for(i=1;i<10;i++){
    for(j=1;j<10;j++){
      if(n==i*j){
        cout << "Yes" << "\n";
        return 0;
      }
    }
  }
  cout << "No" << "\n";
  return 0;
}