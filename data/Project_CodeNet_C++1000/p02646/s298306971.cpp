#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b,v,w;
  int t;
  cin >> a >> v >> b >> w >> t;
  if ( abs(a-b)<=(v-w)*t ) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0; 
}