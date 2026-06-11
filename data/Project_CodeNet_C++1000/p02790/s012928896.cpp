#include <iostream>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  int i;
  if(a>b){
    for(i=0;i<a;i++) cout << b;
    cout << "\n";
    return 0;
  }
  else if(b>=a){
    for(i=0;i<b;i++) cout << a;
    cout << "\n";
    return 0;
  }
}