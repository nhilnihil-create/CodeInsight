#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
    // 小数点以下10桁まで
  cout << fixed << setprecision(10);
  
  if(N%2==0){cout << 0.5<< endl;}
  
  else{cout << (double) ((N+1)/2)/N << endl;}
      
  
}