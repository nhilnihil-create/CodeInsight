//
//  main.cpp
//  AOJ-1172-ans
//
//  Created by Kenta Kodera on 2017/06/18.
//  Copyright ?? 2017??´ Kenta Kodera. All rights reserved.


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <functional>
#include <complex>
#include <stack>
#include <tuple>
#include <array>
#include <ctype.h> // isdigit
#include <cassert>
using namespace std;

int main(){
  
  vector<bool> sieve(300000,true);
  sieve[0]=false, sieve[1]=false;
  for(int i=0; i<=sqrt(300000); i++){
    if(sieve[i]){
      for(int j=2; i*j<300000; j++){
        sieve[i*j] = false;
      }
    }
  }
  
  int n;
  while(cin >>n, n){
    int ans=0;
    for(int i=n+1; i<=2*n; i++){
      if(sieve[i]) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}