#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a;
  cin >> a;
  double b;
  cin >> b;
  cout << ((long long)(b*100 + 0.0000001)*a/100);
  return 0;
}