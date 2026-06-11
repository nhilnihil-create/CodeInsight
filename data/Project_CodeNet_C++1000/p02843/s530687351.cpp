#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int q = n / 100;
  int r = n % 100;
  if(q * 5 >= r){
    cout << 1 << endl;
  }
  else{
    cout << 0 << endl;
  }
}