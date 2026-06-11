#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int out = 0;
  if(a == 1) out += 300000;
  if(b == 1) out += 300000;
  if(a == 2) out += 200000;
  if(b == 2) out += 200000;
  if(a == 3) out += 100000;
  if(b == 3) out += 100000;
  if(a == 1 & b == 1) out += 400000;
  cout << out;
}