#include<iostream>
using namespace std;
int main(){
  long long int a, b;
  cin >> a >> b;
  if(a == 1){
    cout << "1\n";
  }
  else if(b == 1){
    cout << "1\n";
  }
  else if(a * b % 2 == 0){
    cout << a * b / 2 << "\n";
  }
  else{
    cout << (a * b + 1) / 2 << "\n";
  }
}