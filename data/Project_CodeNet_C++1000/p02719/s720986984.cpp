#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  // input
  long long n,k; cin >> n >> k;
 
  // compute
  long long ans;
 
  if(n < k){
    ans = min(n, k - n);
  }else{
    ans = min(n % k, k - (n % k));
  }
 
  // output  
  cout << ans << endl;
  
}