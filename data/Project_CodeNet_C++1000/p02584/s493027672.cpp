#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x,k,d,y;
  cin >> x >> k >> d;
  x = abs(x);
  y = x%d;
  if(abs(y-x)/d > k){
    cout << x - k*d << endl;
    return 0;
  }else{
    k = k - x/d; //ここでx = yとなる
    x = y;
    if(k%2==0){
      cout << x << endl;
    }else{
      cout << abs(x - d) << endl;
    }
  }
  return 0;
}