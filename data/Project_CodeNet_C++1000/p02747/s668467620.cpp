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
  
  string S;
  cin >> S;

  if(S.length()%2 == 1){
    cout << "No" << endl;
    return 0;
  }
  else{
    ll flag = 1;
    for(ll i = 0; i < S.length()/2; i++){
      if(S[2*i] != 'h'|| S[2*i+1]!= 'i'){
        flag = 0;
        break;
      }
    }
    if(flag){
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
    
  }

  return 0;
}
