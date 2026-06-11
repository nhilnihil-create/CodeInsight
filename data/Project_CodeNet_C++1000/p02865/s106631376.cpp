#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(n) n.begin(),n.end()

int kai(int x){
  ll a = 1;
  for(int i=1;i<=x;i++) a *= i;
  return a;
}
int main() {
  ll n;
  cin >> n;
  cout << (n-1)/2<< endl;
}
