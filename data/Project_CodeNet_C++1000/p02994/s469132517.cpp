#include<bits/stdc++.h>
using namespace std;


int main(){
  
  int N, L, i, pos, Sum = 0, Min = 300;
  cin >> N >> L;
  
  for(i = 0; i < N; i++){
    
    Sum += L + i;
    if (L + i < 0){
      Min = min(- L - i, Min);
      pos = -1;
    }else{
      Min = min(L + i, Min);
      pos = 1;
    }
  }
  
  cout << Sum - pos * Min << endl;
  return 0;
}