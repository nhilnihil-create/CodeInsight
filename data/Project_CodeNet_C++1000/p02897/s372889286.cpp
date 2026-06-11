#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  float ans;
  if (N%2 == 0)
    ans = 0.5;
  else{
    ans = N+1;
    ans /= 2*N;
  }
  
  cout << ans << endl;
}