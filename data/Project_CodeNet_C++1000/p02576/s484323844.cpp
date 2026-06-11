#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,X,T;
  cin >> N >> X >> T;
  
  int time = 0;
  
  if(N % X != 0){
    time = (N / X + 1)*T;
  }else{
    time = (N / X)*T;
  }
  cout << time << endl;
  
}