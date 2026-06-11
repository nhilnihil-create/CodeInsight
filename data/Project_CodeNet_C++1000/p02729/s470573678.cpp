#include <bits/stdc++.h>
using namespace std;

int f(int x){
  if(x == 0 || x == 1) return 0;
  
  return x * (x - 1)/2;
}

  
int main(){
  int n, m;
  cin >> n >> m;
  
  cout << f(n) + f(m) << endl;
  return 0;
}
