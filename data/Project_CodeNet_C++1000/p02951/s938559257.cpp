#include<iostream>
using namespace std;
 
int main(){
  int a, b, c, d;
  cin >> a >> b >> c;
  d = a - b;
  if(c <= d){
    cout << "0";
  }
  else{
    cout << c - d;
  }
}