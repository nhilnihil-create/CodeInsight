#include <iostream>
using namespace std;
 
int main() {
  int n,a,i=0;
  cin >> n;
  for(; i < n; i += 1){
    cin >> a;
    if(a %2 == 0 && (!(a %3 == 0 || a %5 == 0))){
      break;
    }
  }
  if(i == n){
    cout << "APPROVED" << endl;
  }else{
    cout << "DENIED" << endl;
  }
  return 0;
}