//
//  main.cpp
//  AOJ-1172
//
//  Created by Kenta Kodera on 2017/06/18.
//  Copyright ?? 2017??´ Kenta Kodera. All rights reserved.
//

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

bool isprime(int n){
  int n_ = sqrt(n);
  
  if(n == 2){
    return true;
  }else if(n%2 == 0){
    return false;
  }else {
    int i = 3;
    while(i <= n_){
      if(n%i == 0){
        return false;
      }
      i += 2;
    }
  }
  return true;
}


int main(){
  
  int n;
  while(cin >> n, n){
    int ans=0;
    for(int i=n+1; i<=2*n; i++){
      if(isprime(i)){
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}