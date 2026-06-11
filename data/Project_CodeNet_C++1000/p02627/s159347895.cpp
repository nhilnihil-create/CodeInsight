#include<iostream>
using namespace std;
int main(){
  char a;
  cin >> a;
  if(a >= 'a' && a <= 'z'){
    cout << "a\n";
    return 0;
  }
  cout << "A\n";
}