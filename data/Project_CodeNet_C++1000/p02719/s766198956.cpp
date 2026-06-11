#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long x, k;
  cin >>x >>k;
  
  long long ans = min(x%k, abs(k-x%k));
  cout << ans <<endl;
}