#include<iostream>
#include<vector>
#include<string>
#include <cassert>
#include <numeric>
 
using namespace std;
 
int main(void){

  int K;
  long long sum = 0;
  cin >> K;
  
  for(int i = 1;i <= K; i++){
   for(int j = 1; j <= K; j++){
    for(int k = 1; k <= K; k++){
      int tmp;
      tmp = gcd(i,j);
      tmp = gcd(tmp,k);
      sum += tmp;
    }
   }
  }
  
  

  cout << sum;
  return 0;
}