#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, K;
  cin >> A >> B >> C;
  cin >> K;
  
  int num;
  for (int i=0 ; i<K ; i++){
    if (A >= B){
      num = i+1;
      B *= 2;
    }
    else{
      num = i;
      break;
    }
  }
  for (int i=0 ; i<K-num ; i++)
    C *= 2;
  
  if (A < B && B < C)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}