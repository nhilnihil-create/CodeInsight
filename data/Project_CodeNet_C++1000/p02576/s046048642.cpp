#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,x,t;
  cin >> n >> x >> t;
  int byk=n/x+(n%x!=0);
  cout << byk*t << '\n';
  return 0;
}