#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  if(n < 10){
    cout << n;
  }
  else if(10 <= n&& 100 > n){
    cout << "9";
  }
  else if(100 <= n&& 1000 > n){
    cout << n - 100 + 1 + 9;
  }
  else if(1000 <= n&& 10000 > n){
    cout << "909";
  }
  else if(10000 <= n&& 100000 > n){
    cout << n - 10000 + 1 + 909;
  }
  else if(n == 100000){
    cout << 90909;
  }
}