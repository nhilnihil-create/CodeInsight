#include <bits/stdc++.h>
using namespace std;

#define MAX 300000



int main(){

  bool is_prime[MAX]={false};
  int sum_prime[MAX]={};
  for(int i=0; i<MAX; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;

  for(int i=2; i<MAX; i++){
    if(is_prime[i])
      for(int j=2; i*j<MAX; j++){
	is_prime[i*j] = false;
      }
  }
  for(int i=2; i<MAX; i++) 
    sum_prime[i] = (is_prime[i] ? 1 : 0) + sum_prime[i-1];
  
  int n;
  while(1){
    cin >> n;
    if(!n) break;
    cout << sum_prime[2*n] - sum_prime[n] << endl;
  }
}