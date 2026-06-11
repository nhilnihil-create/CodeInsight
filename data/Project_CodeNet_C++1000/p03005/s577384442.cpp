#include <bits/stdc++.h>
using namespace std;

int main (){
  
  int N;
  int K;
  int num;
  
  cin >> N >> K;
  
  if(K == 1){
    cout << 0 << endl;
  }
  else{
    num = N - K;
    cout << num << endl;
  }
}