#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

ll gcd(ll A, ll B){
  ll R = A % B;
  if (R == 0){
    return B;
  }
  else{
    return gcd(B, R);
  }
}

int main(){
  ll A, B;
  cin >> A >> B;
  
  ll tar = gcd(A, B);
  
  ll ans = 1, num = 2;
  while (tar != 1){
    bool div = false;
    
    if (num > 1000000){
      ans++;
      break;
    }
    
    while (tar % num == 0){
      tar /= num;
      div = true;
    }
    
    if (div == true){
      ans++;
    }
    
    num++;
  }
  
  cout << ans << endl;
}
