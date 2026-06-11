#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  ll n,a,b;
  cin >>n >>a >>b;
  if(a%2==b%2) cout << (b-a)/2 << endl;
  else{
    ll m = min(a-1, n-b);
    cout << m+1+(b-a-1)/2 << endl;
  }
  return 0; 
}
