#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll j9 = 1000000000;

int main(){
  ll n;
  cin >> n;
  ll y3 = (n-1)/j9 + 1;
  ll x3 = j9 - (n%j9);
  if(n%j9 == 0)  x3 = 0;
  cout << "0 0 1000000000 1 " << x3 << " " << y3;
}