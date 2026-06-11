#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int main(){
  ll a;
  double b;
  cin >> a >> b;  
  cout << (a * static_cast<ll>(b * 100 + FLT_EPSILON)) / 100 << endl;
}