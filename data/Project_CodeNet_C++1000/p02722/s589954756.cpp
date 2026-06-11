#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>

using ll = long long int;
using namespace std;

int main(){

  ll N;
  cin >> N;

  ll ans = 0;

  if(N == 2){
    cout << 1 << endl;
    return 0;
  }

  // n = 0
  for(ll i = 1; i*i <= N-1; i++){
    // if i is divisor of N-1
    if((N-1)%i == 0){
      if(i==1){
        ans++;
      }
      else if(i*i == N-1){
        ans++;
      }
      else{
        ans+=2;
      }
    }
  }

  // n>1;
  vector<ll> divN;
  ans++; // the case K = N
  for(ll i = 2; i*i <= N; i++){
    if(N%i == 0){
      if(i*i == N){
        divN.push_back(i);
      }
      else{
        divN.push_back(i);
        divN.push_back(N/i);
      }
    }
  }

  // count answer
  ll tmp;
  for(ll i = 0; i < divN.size(); i++){
    tmp = N;
    while(tmp%divN[i] == 0){
      tmp = tmp/divN[i];
    }
    if(tmp%divN[i] == 1){
      ans++;
    }
  }

  cerr << "Answer:" << endl;
  cout << ans << endl;

  return 0;
  
}
