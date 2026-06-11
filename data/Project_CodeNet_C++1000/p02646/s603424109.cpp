#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll a,b,v,w,t;
  cin >> a >> v >> b >> w >> t;

  cout << ( (a < b ? ( a + v * t >= b + w * t ? "YES" : "NO") : (a - v * t <= b - w * t ? "YES" : "NO"))) << endl;
}