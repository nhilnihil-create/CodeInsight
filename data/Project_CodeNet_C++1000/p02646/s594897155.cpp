#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,v,w,t;
  cin >> a >> v >> b >> w >> t;
  long long p = abs(a - b);
  long long q = (v - w) * t;
  cout << (p <= q ? "YES" : "NO") << endl;
}