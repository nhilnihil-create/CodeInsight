#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  for(int i = 0 ; i < N+1 ; i++){
    if((int)(i * 1.08) == N){
      cout << i << endl;
      break;
    }else if(i == N){
      cout << ":(" << endl;
    }
  }
}
