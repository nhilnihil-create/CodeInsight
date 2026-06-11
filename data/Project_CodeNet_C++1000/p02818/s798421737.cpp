#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,k;
  string s,t;
  cin >> a >> b >> k;
  if (k > a+b)
    cout << "0 0" << endl;
  else if (k > a)
    cout << "0 " << (a+b-k) << endl;
  else
    cout << a-k << " " << b << endl;
  return 0;
}