#include <iostream>

using namespace std;

int main(){
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  c+=a+b;
  b+=a;
  if(k<=a){
    cout << k;
  }else if(a<k&&k<=b){
    cout << a;
  }else if(k>b){
    cout << a-k+b;
  }
}