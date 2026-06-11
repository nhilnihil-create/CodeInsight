#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll A,B;
  cin>>A>>B;
  ll gcd;
  for(ll i=1;i<=min(A,B);i++) {
    if(A%i==0&&B%i==0) {
gcd=i;
    }
  }
  
  cout<<gcd*(A/gcd)*(B/gcd)<<endl;
}

  
  
  
  