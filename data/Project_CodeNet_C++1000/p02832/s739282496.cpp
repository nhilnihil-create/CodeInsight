#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
  int a,c;
  cin >> a;
  int b = 1;
  bool exist = false;
  for(int i = 0;i<a;i++){
    cin >> c;
    if(c==b){
      b++;
      exist = true;
    }
  }
  if(exist)cout << a - b + 1 << endl;
  else cout << -1 << endl;
}