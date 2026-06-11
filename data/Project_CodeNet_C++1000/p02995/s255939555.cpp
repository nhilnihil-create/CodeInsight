#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t a,b,c,d;
  cin >> a >> b >> c >> d;
  int64_t g=max(c,d),l=min(c,d),n=l;
  while(g%l!=0){
    n=g%l;
    g=l;
    l=n;
  }
  n=c*d/n;
  cout << b-a+1-b/c+(a-1)/c-b/d+(a-1)/d+b/n-(a-1)/n << endl;
  return 0;
}