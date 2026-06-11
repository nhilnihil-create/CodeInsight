#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main(){
  int n; cin >> n;
  ll v = 0, e = 0;
  for(int i = 0; i < n-1; i++){
    ll a, b; cin >> a >> b;
    if(a > b) swap(a, b);
    e += a * (n-b+1);
  }
  for(ll i = 1; i <= n; i++){
    v += i * (n-i+1);
  }
  cout << v - e << endl;
}