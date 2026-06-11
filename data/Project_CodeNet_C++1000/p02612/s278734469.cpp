#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int i = 0;
  
  while (1){
    if (i * 1000 < N){
      i++;
    }
    else{
      break;
    }
  }
    cout << i * 1000 - N << endl; 
}