#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if(n<=8){
    cout<<n;
  }
  else if(9<=n&&n<100){
    cout<<9;
  }
  else if(100<=n&&n<1000){
    cout<<9+n-99;
  }
  else if(1000<=n&&n<10000){
    cout<<909;
  }
  else if(10000<=n&&n<100000){
    cout<<909+n-9999;
  }
  else{
    cout<<90909;
  }
}