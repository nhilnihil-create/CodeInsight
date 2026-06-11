#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,c;
  cin >> a >> b >> c;
  
  if (c-a-b<0) puts("No");
  else {
    if (4*a*b<(c-a-b)*(c-a-b)) puts("Yes");
    else puts("No");
  }
}
