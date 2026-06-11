#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

int main() {
  ll k, x;
  cin >> k >> x;
  vector <ll> a, b;
  for(ll i=0; i<k; ++i){
    a.push_back(x-i);
  }
  for(ll i=1; i<k; ++i){
    b.push_back(x+i);
  }
  for(ll i = a.size() - 1; i>=0; --i)
    cout << a[i] << " ";
  for(ll x:b)
    cout << x << " ";
  cout << endl;  
  return 0;
}