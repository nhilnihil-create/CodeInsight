#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x,y;
  cin >> n >> x >> y;
  if(n%x!=0) {cout << (n/x+1)*y;}
  else {cout << n/x*y;}
  return 0;
}