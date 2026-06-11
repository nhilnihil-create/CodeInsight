#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x;
  long k,d;
  cin >> x >> k >> d;

  if(x<0) x*=-1;

  long shou = x/d;
  long amari = x%d;

  // cout << shou << " " << amari << endl;

  if(k <shou){
    cout << x - k*d << endl;
    return 0;
  }
  
  if(shou%2==k%2){
    cout << amari << endl;
    return 0;
  } else {
    cout << d - amari << endl;
  }
  
  return 0;
}
