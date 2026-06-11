#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N, X;
  int result = 0;
  int k = 0;
  cin >> N >> X;
  vector<int> L(N);
  for(int a = 0;a < N;a++)cin >> L[a];
  for(int a = 1;a <= N;a++){
    k += L[a-1];
    if(k > X){
      cout << a << endl;
      result = 1;
      break;
    } 
    
    
  }
  if(result == 0)cout << N+1 << endl;
}