#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int N;
  cin >> N;
  
  int p = N / 1.08;

  
  if((int)p * 1.08 == N){
    cout <<  p << endl;
  }else if((int)((p-1) * 1.08) == N){
    cout <<  p-1 << endl;
  }else if((int)((p+1) * 1.08) == N){
    cout <<  p+1 << endl;
  }else{
    cout <<  ":(" << endl;
  }
 
}