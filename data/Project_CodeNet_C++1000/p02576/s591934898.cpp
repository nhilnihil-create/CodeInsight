#include <bits/stdc++.h>
using namespace std;
int main() {
int n,x,t,m,a;
  cin >> n >> x >> t;
  a = n/x;
  if(n%x != 0)a++; 
  m = a * t;
  
  cout << m << endl;
}