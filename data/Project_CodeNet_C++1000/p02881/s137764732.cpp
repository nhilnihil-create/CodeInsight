#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nmax = 100005;
int main() {
  ll n;
  cin >> n;
  
  for(ll i=ceil(sqrt(n));i>=1;i--){
    if(n%i == 0){
      ll p = i;
      ll q = n/i;
      cout << (p-1) + (q-1) << endl;
      return(0);
    }
  }
  
  return(0);
}