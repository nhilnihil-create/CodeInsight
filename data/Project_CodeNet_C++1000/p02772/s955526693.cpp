#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <functional>
#include <cstdint>
#define REP(i, n) for(ll i = 0; i < n; i++)
using ll = long long;
using namespace std;

int main() {

  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string ans="APPROVED";
  int n;
  cin >> n;
  int a[n];
  REP(i,n) cin >> a[i];

  REP(i,n){
    if (a[i] % 2 == 0){
      if(a[i]%3!=0 && a[i]%5!=0)
        ans = "DENIED"; 
    }
  }
    
  cout << ans << endl;

}
  
