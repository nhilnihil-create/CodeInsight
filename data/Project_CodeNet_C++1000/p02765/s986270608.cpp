#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, r;
  cin >> n >> r;
  int add = 0;
  if(n < 10){
    add = 100 * (10 - n);
    r += add;
  }
  cout << r << endl;
  return 0;
}