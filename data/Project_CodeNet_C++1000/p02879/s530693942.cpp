#include<iostream>
#include<string>
using namespace std;
int main(){
  int a, b;
  cin >> a >> b;
  if(a >= 10 || b >= 10){
    cout << "-1\n";
    return 0;
  }
  cout << a * b << "\n";
}