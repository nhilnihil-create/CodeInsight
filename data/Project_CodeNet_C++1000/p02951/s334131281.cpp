#include<iostream>
#include<string>
using namespace std;
int main(){
  int a, b, c ,n = 0;
  cin >> a >> b >> c;
  n = a- b;
  if(c <= n){
    cout << "0\n";
    return 0;
  }
  cout << c - n << "\n";
}