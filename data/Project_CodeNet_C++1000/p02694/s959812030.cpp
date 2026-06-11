#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a,b,i;
  b = 100;
  i = 0;
  cin >> a;
  while(b < a){
    long long c = b / 100;
    b = b + c;
    i++;
  }
  cout << i;
}