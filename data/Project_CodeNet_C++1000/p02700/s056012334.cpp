#include <bits/stdc++.h>
using namespace std;
void x(int n){
  if(n==0) cout << "Yes" << endl;
  else cout << "No" << endl;
  exit(0);
}
int main() {
  int a,b,c,d; cin>>a>>b>>c>>d;
  while(1){
    c-=b;
    if(c<=0) x(0);
    a-=d;
    if(a<=0) x(1);
  }
}