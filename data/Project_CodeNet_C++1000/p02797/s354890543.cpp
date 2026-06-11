#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,S;
  cin >> N >> K >> S;
  int count=0;
  int x;
  for(int i=1e9;i>=1;i--){
    if(i!=S){
      x=i;
      break;
    }
  }
  for(int i=0;i<N;i++){
    if(count>=K){
      cout << x;
    }else{
      cout << S;
      count++;
    }
    if(i==N-1){
      cout << endl;
    }else{
      cout << " ";
    }
  }
  return 0;
}
