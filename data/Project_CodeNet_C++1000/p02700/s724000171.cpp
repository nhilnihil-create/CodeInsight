#include<iostream>
using namespace std;
int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while(a > 0){
    c = c - b;
    if(c <= 0){
      cout << "Yes\n";
	  break;
    }
    a = a - d;
    if(a <= 0){
      cout << "No\n";
      break;
    }
  }
}