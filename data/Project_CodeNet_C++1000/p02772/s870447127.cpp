#include <iostream>
using namespace std;

int main() {
  int n,a,i=0,x=0;
  cin >> n;
  for(; i < n; i += 1){
    cin >> a;
    if(a %2 == 0 && (!(a %3 == 0 || a %5 == 0))){
      x += 1;
    }
  }
  if(x == 0){
    cout << "APPROVED" << endl;
  }else{
    cout << "DENIED" << endl;
  }
  return 0;
}
