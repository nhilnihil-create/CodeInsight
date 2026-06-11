#include <bits/stdc++.h>
using namespace std;

int main(void){
   
  int N,K,count = 0;
  cin >> N >> K;

  while(N>0){
      N/=K;
      count++;
  }
  cout << count <<endl;
}