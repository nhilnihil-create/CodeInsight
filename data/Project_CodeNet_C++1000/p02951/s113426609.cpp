#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
using ll = long long;
int main(){
  int a,b,c;
  cin >> a >>b >> c;
  
  int f = a-b;
  int z = (c >= f)?c-f:0;
  cout << z<<endl;
  return 0;
}
