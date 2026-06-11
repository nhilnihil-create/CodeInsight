#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,v,b,w,t;
  cin >> a>> v >> b >> w >> t;
  long long d=abs(a-b);
  long long x=abs(v-w);
  if(v>w && d<=x*t) cout << "YES";
  else cout << "NO";
  
}