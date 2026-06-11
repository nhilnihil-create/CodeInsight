#include<iostream>
using namespace std;
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if(a == b || a == c || b == c){
    if(a == b && a == c){
      cout << "No\n";
    }
    else{
      cout << "Yes\n";
    }
  }
  else{
    cout << "No\n";
  }
}