#include<bits/stdc++.h>
using namespace std;

int main(){
  int x;
  cin >> x;
  int n=x%100,m=x/100,a=0;
  a=(n%5==0)?n/5:n/5+1;
  if(m<a)
    cout << 0 << endl;
  else 
    cout << 1 << endl;
  return 0;
}