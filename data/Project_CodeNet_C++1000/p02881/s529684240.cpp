#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#include <numeric>
using namespace std;


int main() {
 long long n;
 cin >> n;
 
 long long ans = n -1;
 
 for(long long i = 2; i <= sqrt(n); i++) {
  if(n % i == 0) {
   ans = i + n / i - 2;
   }
   }
   
   cout << ans;
}