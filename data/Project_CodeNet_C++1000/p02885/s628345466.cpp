#include<iostream>
#include<string>
using namespace std;
int main(){
  int a, b;
  cin >> a >> b;
  b = b * 2;
  if(a < b){
    cout << "0\n";
    return 0;
  }
  cout << a - b;
}