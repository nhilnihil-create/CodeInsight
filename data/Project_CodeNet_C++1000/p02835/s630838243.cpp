#include<iostream>
using namespace std;
int main(){
  int a, b, c, s;
  cin >> a >> b >>c;
  s = a + b + c;
  if(s <= 21){
    cout << "win\n";
    return 0;
  }
  cout << "bust\n";
}