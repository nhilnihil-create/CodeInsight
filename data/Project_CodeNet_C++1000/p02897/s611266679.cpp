#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  double a ;
  if(n % 2 == 1)
    a = n / 2 + 1;
  else
    a = n/2;
  cout << a/double(n);
}