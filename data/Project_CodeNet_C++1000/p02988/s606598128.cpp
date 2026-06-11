#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,i,M;
  cin >> a;
  M = 0 ; 
  vector<int> vec(a);
  for(i=0;i<a;i++)cin >> vec[i];
  for(i=1;i<a-1;i++)if (vec[i-1]<vec[i] && vec[i] <vec[i+1])M++;
  for(i=1;i<a-1;i++)if (vec[i-1]>vec[i] && vec[i] >vec[i+1])M++;


  cout << M << endl;
  
  
}