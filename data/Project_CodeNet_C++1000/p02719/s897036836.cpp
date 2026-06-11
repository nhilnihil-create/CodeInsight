#include <bits/stdc++.h>
using namespace std;

int main(){
  long n, k;
  cin >> n >> k;
  long p, m;
  p = n % k;
  m = -(p - k);
  if(p >= m){
  	n = m;
  }
  else{
  	n = p;
  }
  cout << n << endl;
  return 0;
}