#include <iostream>
using namespace std;
int main(){
  long long int a,b,c,d=0;
  cin >> a >> b >> c;
  if(c>a){
    b = max(a + b - c,d);
    a = 0;
  }
  else a -= c;
  cout << a << " " << b;
}