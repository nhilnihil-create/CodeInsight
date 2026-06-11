#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n; cin >> n;
  ll sum = 0;
  ll digit = 0;
  for(int i = 0; i < n; i++){
    ll a, b; cin >> a >> b;
    digit += b;
    sum += a * b;
  }
  cout << digit - 1 + (sum - 1) / 9 << endl;
}
