#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t a,b,c;
  cin >> a >> b >> c;
  int64_t n=c-a-b;
  bool ans=(n>0&&4*a*b<n*n);
  cout << (ans?"Yes":"No") << endl;
  return 0;
}

